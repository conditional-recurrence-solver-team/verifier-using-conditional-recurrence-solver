from z3 import *
from aux_z3 import *
s = set()
n = Int("n")
N0 = Int("N0")
s.add(N0 >= 0)
solver = Solver()
solver.set("timeout", 2000)
x1 = Int("x1")
x2 = Function("x2", IntSort(), IntSort())
x3 = Int("x3")
s.add(x1 == 268435441)
s.add(x2(0) == x1)
s.add(ForAll(n, Implies(n >= 0, x2(n + 1) == If(True, x2(n) - 2, x2(n) - 2))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, x2(n) == 268435441 - 2*n)))
#################################
s.add(x3 == x2(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), x2(n) > 1)))
s.add(Not(x2(N0) > 1))
########## assert ##########
############################
