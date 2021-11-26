from z3 import *
from aux_z3 import *
s = set()
n = Int("n")
N0 = Int("N0")
s.add(N0 >= 0)
solver = Solver()
solver.set("timeout", 2000)
l1 = Int("l1")
l2 = Function("l2", IntSort(), IntSort())
l3 = Int("l3")
n1 = Int("n1")
i1 = Int("i1")
i2 = Function("i2", IntSort(), IntSort())
i3 = Int("i3")
j1 = Int("j1")
j2 = Function("j2", IntSort(), IntSort())
j3 = Int("j3")
tmp0 = Int("tmp0")
s.add(tmp0 >= 0)
s.add(n1 == tmp0)
s.add(i1 == 0)
s.add(j1 == 0)
s.add(l1 == 0)
s.add(i2(0) == i1)
s.add(ForAll(n, Implies(n >= 0, i2(n + 1) == If(Mod(l2(n), 2) == 0, i2(n) + 1, i2(n)))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 2*i2(n) == If(Mod(n, 2) == 0, n, n + 1))))
#################################
s.add(i3 == i2(N0))
s.add(j2(0) == j1)
s.add(ForAll(n, Implies(n >= 0, j2(n + 1) == If(Mod(l2(n), 2) == 0, j2(n), j2(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 2*j2(n) == If(Mod(n, 2) == 0, n, n - 1))))
#################################
s.add(j3 == j2(N0))
s.add(l2(0) == l1)
s.add(ForAll(n, Implies(n >= 0, l2(n + 1) == If(Mod(l2(n), 2) == 0, l2(n) + 1, l2(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, l2(n) == If(Mod(n, 2) == 0, n, n))))
#################################
s.add(l3 == l2(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), l2(n) < n1)))
s.add(Not(l2(N0) < n1))
########## assert ##########
############################
