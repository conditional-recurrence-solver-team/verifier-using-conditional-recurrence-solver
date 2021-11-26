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
s.add(x1 == 0)
s.add(x2(0) == x1)
s.add(ForAll(n, Implies(n >= 0, x2(n + 1) == If(x2(n) < 65521, x2(n) + 1, x2(n) + 2))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, x2(n) == If(And(0 <= n, n < 65521), n, 2*n - 65521))))
#################################
s.add(x3 == x2(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), x2(n) < 268435455)))
s.add(Not(x2(N0) < 268435455))
########## assert ##########
############################
