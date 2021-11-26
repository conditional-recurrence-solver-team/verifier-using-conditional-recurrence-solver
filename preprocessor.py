import utils
from pycparser import parse_file, c_generator

class MyCGenerator(c_generator.CGenerator):
    def visit_For(self, n):
        s = ''
        if n.init: s += '%s;\n' % self.visit(n.init)
        if n.cond: s += 'while (%s) {\n' % self.visit(n.cond)
        s += self._generate_stmt(n.stmt, add_indent=True)
        if n.next: s += self._generate_stmt(n.next, add_indent=True)
        s += '}\n'
        return s

def preprocess(filename, out):
    to_preprossed_path = utils.c2z3_preprocess(filename)
    # cpp_path = '/usr/local/bin/cpp-9'
    cpp_path = '/opt/homebrew/bin/cpp-11'
    ast = parse_file(to_preprossed_path, use_cpp=True)
    # ast = parse_file(to_preprossed_path)
    generator = MyCGenerator()
    with open(out, 'w') as fp:
        fp.write(generator.visit(ast))
    return out

if __name__ == '__main__':
    preprocess('/home/wangchenglin/Downloads/icra-master/WALi-OpenNWA/Examples/cprover/tests/frankenstein/HOLA/11.c', 'temp/preprocessed.c')
