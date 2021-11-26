# Currently, for the inter-procedure analysis, functions are assumed to be non-recursive
# and there is only one 'return' statement in the function body.

from pycparser import c_ast
from sympy.tensor.index_methods import get_contraction_structure
from sympy.utilities.misc import translate
import utils
import z3
import re
from rec_solver.PRS.mathematica_manipulation import session
import analyze_loop
import time

z3.set_option(max_args=100000000, max_lines=100000000, max_depth=10000000000, max_visited=10000000)
# z3.set_option(timeout=10)
sim = z3.Then('ctx-simplify', 'unit-subsume-simplify')
name_prefix = '_C2Z3_'
fp_index = 0
g_constraint = None

class C2Z3Visitor(c_ast.NodeVisitor):
    def __init__(self):
        self.main_visitor = MainVisitor()
        self.func_visitor = MainVisitor()
        self.func_mappings = {}
        self.func_signatures = {}
        self.func_N_constraints = {}
        self.func_N_cnt = {}
        self.extern = set()

    def visit_FileAST(self, n):
        for ext in n.ext:
            if self._is_main(ext):
                self.main_visitor.add_ctx(self.func_signatures, self.func_mappings, self.extern, self.func_N_constraints, self.func_N_cnt)
                var_values_dict = self.main_visitor.visit(ext)
                assertions = self.main_visitor.get_assertions()
            elif self._is_FuncDef(ext):
                func_name = ext.decl.name
                if func_name.endswith('assert'): continue
                signature = []
                if ext.decl.type.args is not None:
                    signature = self.func_visitor.visit(ext.decl.type.args)
                self.func_visitor.reset_counters()
                self.func_signatures[func_name] = signature
                self.func_visitor.add_ctx(self.func_signatures, self.func_mappings, self.extern, self.func_N_constraints, self.func_N_cnt)
                var_values_dict = self.func_visitor.visit(ext)
                #TODO Currently, all functions are assumed not to modify global variables
                ret_value = self._extract_returned_value(var_values_dict)
                self.func_mappings[func_name] = ret_value
                self.func_N_constraints[func_name] = self.func_visitor.N_constraints
                self.func_N_cnt[func_name] = self.func_visitor.N_index
                self.func_visitor.reset()
            elif self._is_FuncDecl(ext):
                if self._is_extern(ext.storage):
                    self.extern.add(ext.name)

        for a in assertions:
            self.check_assertion(self.main_visitor.get_z3_vars(), self.main_visitor.N_constraints, self.main_visitor.N_index, a)

    def _is_extern(self, storage):
        return 'extern' in storage

    def _is_main(self, n):
        return self._is_FuncDef(n) and n.decl.name == 'main'

    def _is_FuncDef(self, n):
        return isinstance(n, c_ast.FuncDef)

    def _is_FuncDecl(self, n):
        return isinstance(n, c_ast.Decl) and isinstance(n.type, c_ast.FuncDecl)

    def _translate_main_function(self, n):
        for statement in n.body.block_items:
            self.visit(statement)
        
    def _c2z3(self, var_values_dict, assertion, z3vars, N_constraints, N_index):
        res = 'from z3 import *\n'
        res += 's = set()\n'
        res += 'solver = Solver()\n'
        res += 'n = Int("n")\n'
        for var in z3vars:
            if z3.is_int(var):
                res += '%s = z3.Int("%s")\n' % (var, var)
            else:
                raise Exception('Not supported')
        for i in range(N_index):
            res += 'N%d = z3.Int("N%d")\n' % (i, i)
            res += 's.add(N%d >= 0)\n' % i
        for cons in N_constraints:
            res += 's.add(%s)\n' % cons
        res += 's.add(Not(%s))\n' % assertion
        res += ('res = solver.check(s)\n')
        res += 'if res == sat:\n'
        res += '\tprint(solver.model())\n'
        res += 'else:\n'
        res += '\tprint("Correct!")\n'
        return res
    
    def check_assertion(self, z3vars, N_constraints, N_index, assertion):
        global fp_index
        # solver = z3.Solver()
        sim = z3.Then('ctx-simplify', 'qe', 'ctx-solver-simplify')
        solver = z3.ParOr(z3.Then('ctx-simplify', 'qe', 'ctx-solver-simplify', 'smt'), z3.Then('ctx-simplify', 'qe', 'ctx-solver-simplify', 'qfnra-nlsat'), z3.Tactic('smt')).solver()
        solver.set('timeout', 1000000000)
        # solver = z3.Then('ctx-simplify', 'qe', 'nlsat').solver()
        solver = z3.Solver()
        res = None
        from z3 import And, Or, If, Implies, Not, Real, ForAll, ToReal
        for over_approx in [False, True]:
            s = set()
            n = z3.Int('n')
            z3variables = {str(var): z3.Int(str(var)) for var in z3vars}
            z3variables.update({'N%d' % i: z3.Int('N%d' % i) for i in range(N_index)})
            for cons in N_constraints:
                if over_approx and z3.is_quantifier(cons): continue
                s.add(cons)
                # print(repr(simplified))
            for i in range(N_index):
                N_name = 'N%d' % i
                z3variables[N_name] = z3.Int(N_name)
                s.add(z3variables[N_name] >= 0)
                # print(z3variables[N_name] >= 0)
            # s.add(z3.Int('c2z3_tmp_i_0') == 3)
            s.add(z3.Not(assertion))
            # simplified = z3.simplify(z3.substitute(assertion, (z3.Int('c2z3_tmp_i_0'), z3.IntVal(4))))
            # print(simplified)
            # print(s)
            # simplified = z3.simplify(simplified, som=True, arith_lhs=True, sort_sums=True, local_ctx=True)
            # simplified = z3.Tactic('propagate-ineqs')(simplified)[0]
            start_time = time.time()
            res = solver.check(z3.And(*s))
            if res == z3.unknown:
                n = Real('n')
                for stmt in s:
                    for v in utils.all_z3_symbols(stmt):
                        if '(' in str(v): continue
                        exec('%s = Real("%s")' % (v, v))
                new_s = set()
                for stmt in s:
                    new_s.add(eval(str(stmt).replace('\n', '')))
                res = solver.check(new_s)
                if res == z3.sat:
                    res = z3.unknown
            if res == z3.sat and over_approx:
                print('Unknown')
                return 'Unknown'
            elif res == z3.sat:
                print('Wrong')
                print(solver.model())
                return 'Wrong'
                break
            elif res == z3.unknown and over_approx:
                print('Unknown')
                return 'Unknown'
            elif res == z3.unknown:
                continue
            elif res == z3.unsat:
                print('Correct!')
                return 'Correct'
                break

    def _extract_returned_value(self, values_dict):
        try:
            return values_dict[z3.Int('ret')]
        except:
            return None

class MainVisitor(c_ast.NodeVisitor):
    def __init__(self):
        self.reset()

    def reset(self):
        self.symbol_values = {}
        self.symbol_index = {}
        self.tmp_index = 0
        self._z3var = set()
        self.assertions = []
        self.quantified_assertions = []
        self.cached_quantified_assertions = []
        self.cached_assertions = []
        self.encounter_return = False
        self.conditions = []
        self.cached_conditions = []
        self.N_index = 0
        self.N_constraints = []
        self.cached_N_constraints = []
        self.func_mappings = {}
        self.func_signatures = {}
        self.func_N_constraints = {}
        self.func_N_cnt = {}
        self.func_call_index = {}
        self.unknown = 0
        self.variables_loop = set()

    def reset_counters(self):
        self.tmp_index = 0

    def visit_Decl(self, n):
        var_name = n.name
        var = z3.Int(var_name)
        self.symbol_index[var] = 0
        res = {}
        if n.init is None:
            var_initial_value = self._gen_var_temp_value(var_name)
            res[var] = var_initial_value
        else:
            init = self.visit(n.init)
            res[var] = init
        return res

    def visit_Assignment(self, n):
        lvalue = self.visit(n.lvalue)
        rvalue = self.visit(n.rvalue)
        computed_rvalue = rvalue
        if n.op == '=':
            computed_rvalue = rvalue
        elif n.op == '+=':
            computed_rvalue = lvalue + rvalue
        elif n.op == '-=':
            computed_rvalue = lvalue - rvalue
        elif n.op == '*=':
            computed_rvalue = lvalue * rvalue
        else:
            raise Exception('Not supported')
        # computed_rvalue = z3.substitute(computed_rvalue, [(var, value) for var, value in self.symbol_values.items()])
        computed_rvalue = z3.simplify(computed_rvalue)
        return {lvalue: computed_rvalue}

    def visit_BinaryOp(self, n):
        left = self.visit(n.left)
        right = self.visit(n.right)
        if n.op == '+':
            return left + right
        elif n.op == '-':
            return left - right
        elif n.op == '*':
            return left * right
        elif n.op == '/':
            return left / right
        elif n.op == '%':
            return left % right
        elif n.op == '>':
            return left > right
        elif n.op == '>=':
            return left >= right
        elif n.op == '<':
            return left < right
        elif n.op == '<=':
            return left <= right
        elif n.op == '==':
            return left == right
        elif n.op == '!=':
            return left != right
        elif self._is_bool_binary_op(n.op):
            bool_left = self._arith2bool(left)
            bool_right = self._arith2bool(right)
            if n.op == '&&':
                return z3.And(bool_left, bool_right)
            elif n.op == '||':
                return z3.Or(bool_left, bool_right)
            else:
                raise Exception('Not supported')
        else:
            raise Exception('Not supported')

    def visit_Constant(self, n):
        if n.type == 'int':
            if n.value.startswith('0x'):
                return z3.IntVal(int(n.value, 16))
            else:
                return z3.IntVal(n.value)
        else:
            raise Exception('Not supported')

    def visit_ID(self, n):
        id_var = z3.Int(n.name)
        if not n.name.endswith('assert'):
            self.variables_loop.add(id_var)
        # if not n.name.endswith('assert'):
        #     self._z3var.add(id_var)
        return id_var

    def visit_UnaryOp(self, n):
        if n.op == '-':
            return -self.visit(n.expr)
        elif n.op == '+':
            return self.visit(n.expr)
        elif n.op == 'p++' or n.op == '++':
            name = self.visit(n.expr)
            return {name: self.visit(n.expr) + 1}
        elif n.op == 'p--' or n.op == '--':
            name = self.visit(n.expr)
            return {name: self.visit(n.expr) - 1}
        elif n.op == '!':
            expr = self.visit(n.expr)
            if z3.is_bool(expr):
                return z3.Not(expr)
            else:
                return z3.If(expr == 0, 1, 0)
        else:
            print(n.op)
            raise Exception('Not supported')

    def visit_ExprList(self, n):
        exprs_list = [self.visit(expr) for expr in n.exprs]
        return exprs_list

    def visit_While(self, n):
        cond = self._arith2bool(self.visit(n.cond))
        old_cached_assertions = self.cached_assertions
        self.cached_assertions = []
        self.variables_loop = set()
        stmt = self.visit(n.stmt)
        #TODO this is wrong, should be fixed later
        self.cur_values = self.symbol_values
        try:
            with open('num_rec.txt', 'a') as fp:
                fp.write('1\n')
            with open('recurrence.txt', 'a') as fp:
                time_start = time.time()
                res = utils.solve_rec(stmt, list(self.variables_loop), self.cur_values)
                fp.write(str(time.time() - time_start) + '\n')
        except:
            with open('recurrence.txt', 'a') as fp:
                time_start = time.time()
                res = utils.solve_rec(stmt, list(self.variables_loop), {})
                fp.write(str(time.time() - time_start) + '\n')
        # res = utils.solve_rec(stmt, list(self.variables_loop), self.cur_values)
        # analyze_loop.num_iterations(cond, res, n)
        self.variables_loop = set()
        mapping = [(var, closed) for var, closed in res.items()]
        # for var in utils.all_z3_symbols(cond):
        #     exec('%s = z3.Int("%s")' % (var, var))
        for var, closed in mapping:
            exec('%s = closed' % var)
        # translated_cond = z3.substitute(cond, *mapping)
        # translated_cond = eval(str(cond))
        translated_cond = utils.my_substitute(cond, mapping)
        index = z3.Int('n')
        N = z3.Int('N%d' % self.N_index)
        # self.cached_N_constraints.append(z3.substitute(z3.Not(translated_cond), (index, N)))
        self.cached_N_constraints.append(utils.my_substitute(z3.Not(translated_cond), [(index, N)]))
        self.cached_N_constraints.append(z3.ForAll(index, z3.Implies(z3.And(0 <= index, index < N), translated_cond)))
        # self.cached_assertions = [z3.substitute(a, *mapping) for a in self.cached_assertions]
        from z3 import Or, And, Not, If, Implies
        new_assertions = []
        for a in self.cached_assertions:
            new_assertions.append(eval(str(a)))
        # self.cached_assertions = [eval(str(a)) for a in self.cached_assertions]
        self.cached_assertions = new_assertions
        self.cached_quantified_assertions.extend([(a, N) for a in self.cached_assertions])
        self.cached_assertions = old_cached_assertions
        self.N_index += 1
        res = {var: z3.substitute(closed, (index, N)) for var, closed in res.items()}
        return res

    def visit_If(self, n):
        cond = self._arith2bool(self.visit(n.cond))
        iftrue_stmt = self.visit(n.iftrue)
        if self.encounter_return:
            self.cached_conditions.append(z3.Not(cond))
        self._add_condition_to_cached_assertions(cond)
        self.iftrue_cached_asssertions = self.cached_assertions
        self.cached_assertions = []
        iftrue_encounter_return = self.encounter_return
        self.encounter_return = False
        try:
            iffalse_stmt = self.visit(n.iffalse)
            if self.encounter_return:
                self.cached_conditions.append(cond)
            self._add_condition_to_cached_assertions(z3.Not(cond))
            self.cached_assertions = self.iftrue_cached_asssertions + self.cached_assertions
        except:
            iffalse_stmt = {}
            self.cached_assertions = self.iftrue_cached_asssertions
        iffalse_encounter_return = self.encounter_return
        self.encounter_return = self.encounter_return or iftrue_encounter_return
        all_var = set(iftrue_stmt).union(set(iffalse_stmt))
        res = {}
        for var in all_var:
            true_value = var
            false_value = var
            if not iftrue_encounter_return:
                true_value = iftrue_stmt.setdefault(var, var)
            if not iffalse_encounter_return:
                false_value = iffalse_stmt.setdefault(var, var)
            res[var] = z3.If(cond, true_value, false_value)
        self.encounter_return = False
        return res

    def visit_Compound(self, n):
        res = {}
        for stmt_node in n.block_items:
            cached_assertions = self.cached_assertions
            self.cached_assertions = []
            stmt = self.visit(stmt_node)
            self._update_cached_assertion(res)
            self.cached_assertions = cached_assertions + self.cached_assertions
            old_values = list(res.items())
            if stmt is None: continue
            for var in stmt.keys():
                value = stmt[var]
                computed_value = z3.substitute(value, *old_values)
                stmt[var] = utils.pull_ite(computed_value)
            if isinstance(stmt_node, c_ast.While):
                self._update_cached_N_constraints(res)
            res.update(stmt)
            # res.update(z3.simplify(stmt, pull_cheap_ite=True, ite_extra_rules=True))
        # print(self.cached_N_constraints)
        return res.copy()

    def visit_FuncCall(self, n):
        name = str(self.visit(n.name))
        # if n.args is not None:
        try:
            args = self.visit(n.args)
        except:
            args = []

        if name.endswith('__VERIFIER_assert'):
            self.cached_assertions.append(args[0])
            return {}
        if name.startswith('unknown') or name == 'nondet' or name == '__VERIFIER_nondet_int' or name == '__VERIFIER_nondet_uint' or name.startswith('__VERIFIER_nondet'):
            res = z3.Int('unknown%d' % self.unknown)
            self.unknown += 1
            return res
        if name in self.extern:
            return {}

        sigs = self.func_signatures[name]
        mapping = self.func_mappings[name]
        subs_pairs_list = []
        for arg, para in zip(args, sigs):
            para_name = list(para.values())[0]
            subs_pairs_list.append((para_name, arg))
        self.func_call_index.setdefault(name, 0)
        if name in self.func_N_constraints:
            N_contraints = self.func_N_constraints[name]
            N_cnt = self.func_N_cnt[name]
            for cons in N_contraints:
                instantiate_cons = cons
                for i in range(N_cnt):
                    call_index = self.func_call_index[name]
                    old_N = z3.Int('N%d' % i)
                    new_N = z3.Int('%sN%d_%d' % (name, i, call_index))
                    subs_pair = (old_N, new_N)
                    instantiate_cons = z3.substitute(instantiate_cons, (z3.Int('N%d' % i), z3.Int('%sN%d_%d' % (name, i, call_index))))
                    subs_pairs_list.append(subs_pair)
                    self.cached_N_constraints.append(new_N >= 0)
                instantiate_cons = z3.substitute(instantiate_cons, *subs_pairs_list)
                self.cached_N_constraints.append(instantiate_cons)
            self.func_call_index[name] += 1
        if len(subs_pairs_list) != 0:
            return z3.substitute(mapping, *subs_pairs_list)
        return mapping

    def visit_FuncDecl(self, n):
        # params = self.visit(n.type)
        params = self.visit(n.args)
        return params

    def visit_ParamList(self, n):
        param_list = []
        for param in n.params:
            param_list.append(self.visit(param))
        return param_list

    def visit_FuncDef(self, n):
        body = n.body
        try:
            params = self.visit(n.decl.type)
            for param in params:
                self.symbol_values.update(param)
        except:
            pass
        for stmt_node in body:
            stmt = self.visit(stmt_node)
            if self.encounter_return:
                self.conditions.append(False)
            self._update_cached_assertion(self.symbol_values)
            self._update_cached_conditions(self.symbol_values)
            self._update_cached_N_constraints(self.symbol_values)
            self._sync_conditions()
            self._sync_assertions()
            self._sync_N_constraints()
            old_values = list(self.symbol_values.items())
            for var in stmt.keys():
                value = stmt[var]
                print(old_values)
                computed_value = z3.substitute(value, *old_values)
                stmt[var] = z3.simplify(computed_value)
            self.symbol_values.update(stmt)
        return self.symbol_values.copy()

    def visit_Return(self, n):
        self.encounter_return = True
        if n.expr is not None:
            expr = self.visit(n.expr)
        else:
            return {}
        # TODO this dummy returned value should be replaced in future
        return {}

    def _update_cached_assertion(self, values_dict):
        values = [(var, value) for var, value in values_dict.items()]
        # self.cached_assertions = [z3.substitute(a, *values) for a in self.cached_assertions]
        self.cached_assertions = [utils.my_substitute(a, values) for a in self.cached_assertions]
        self.cached_quantified_assertions = [(z3.substitute(a, *values), N) for a, N in self.cached_quantified_assertions]

    def _update_cached_conditions(self, values_dict):
        values = [(var, value) for var, value in values_dict.items()]
        self.cached_conditions = [z3.substitute(c, *values) for c in self.cached_conditions]

    def _update_cached_N_constraints(self, values_dict):
        values = [(var, value) for var, value in values_dict.items()]
        constraints = [z3.substitute(c, *values) for c in self.cached_N_constraints]
        self.cached_N_constraints = constraints

    def _sync_N_constraints(self):
        self.N_constraints.extend(self.cached_N_constraints)
        self.cached_N_constraints = []

    def _sync_conditions(self):
        self.conditions.extend(self.cached_conditions)
        self.cached_conditions = []

    def _add_condition_to_cached_assertions(self, cond):
        updated = [z3.Implies(cond, a) for a in self.cached_assertions]
        self.cached_assertions = updated

    def _sync_assertions(self):
        premises = self.conditions + [True]
        premise = z3.simplify(z3.And(*sim(z3.And(*premises))[0]))
        self.assertions.extend([z3.Implies(premise, a) for a in self.cached_assertions])
        n = z3.Int('n')
        self.quantified_assertions.extend([z3.Implies(premise, z3.ForAll(n, z3.Implies(z3.And(0 <= n, n < N), a))) for a, N in self.cached_quantified_assertions])
        self.cached_assertions = []
        self.cached_quantified_assertions = []

    def get_z3_vars(self):
        return self._z3var

    def get_assertions(self):
        return self.assertions + self.quantified_assertions

    def add_ctx(self, func_signatures, func_mappings, extern, func_N_constraints, func_N_cnt):
        self.func_signatures.update(func_signatures)
        self.func_mappings.update(func_mappings)
        self.extern = extern
        self.func_N_constraints = func_N_constraints
        self.func_N_cnt = func_N_cnt

    def _gen_var_temp_value(self, var):
        index = self.tmp_index
        self.tmp_index += 1
        tmp_var = z3.Int('c2z3_tmp_%s_%d' % (var, index))
        self._z3var.add(tmp_var)
        return tmp_var

    def _is_bool_binary_op(self, op):
        return op == '&&' or op == '||'

    def _contains_unknown(self, stmt):
        return 'unknown' in str(stmt)

    def _arith2bool(self, v):
        if z3.is_arith(v):
            return v != 0
        return v

if __name__ == '__main__':
    from pycparser import parse_file
    to_preprossed_path = utils.c2z3_preprocess('examples/inter1.c')
    ast = parse_file(to_preprossed_path, use_cpp=True)
    visitor = C2Z3Visitor()
    visitor.visit(ast)
    session.terminate()
