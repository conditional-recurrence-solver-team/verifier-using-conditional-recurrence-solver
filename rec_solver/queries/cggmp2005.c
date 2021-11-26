from z3 import *
from aux_z3 import *
s = set()
n = Int("n")
N0 = Int("N0")
s.add(N0 >= 0)
solver = Solver()
solver.set("timeout", 2000)
i1 = Int("i1")
i2 = Int("i2")
i3 = Function("i3", IntSort(), IntSort())
i4 = Int("i4")
j1 = Int("j1")
j2 = Int("j2")
j3 = Function("j3", IntSort(), IntSort())
j4 = Int("j4")
tmp1 = Int("tmp1")
tmp0 = Int("tmp0")
s.add(i1 == tmp0)
s.add(j1 == tmp1)
s.add(i2 == 1)
s.add(j2 == 10)
s.add(i3(0) == i2)
s.add(ForAll(n, Implies(n >= 0, i3(n + 1) == If(True, i3(n) + 2, i3(n) + 2))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, i3(n) == 2*n + 1)))
#################################
s.add(i4 == i3(N0))
s.add(j3(0) == j2)
s.add(ForAll(n, Implies(n >= 0, j3(n + 1) == If(True, j3(n) - 1, j3(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, j3(n) == 10 - n)))
#################################
s.add(j4 == j3(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), j3(n) >= i3(n))))
s.add(Not(j3(N0) >= i3(N0)))
########## assert ##########
############################
