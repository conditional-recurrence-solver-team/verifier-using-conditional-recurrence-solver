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
y1 = Int("y1")
z1 = Int("z1")
z2 = Function("z2", IntSort(), IntSort())
z3 = Int("z3")
s.add(x1 == 0)
s.add(y1 == 10000000)
s.add(z1 == 5000000)
s.add(z2(0) == z1)
s.add(ForAll(n, Implies(n >= 0, z2(n + 1) == If(x2(n) >= 5000000, z2(n) + 1, z2(n)))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, z2(n) == If(And(0 <= n, n < 5000000), 5000000, n))))
#################################
s.add(z3 == z2(N0))
s.add(x2(0) == x1)
s.add(ForAll(n, Implies(n >= 0, x2(n + 1) == If(x2(n) >= 5000000, x2(n) + 1, x2(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, x2(n) == If(And(0 <= n, n < 5000000), n, n))))
#################################
s.add(x3 == x2(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), x2(n) < y1)))
s.add(Not(x2(N0) < y1))
########## assert ##########
############################
