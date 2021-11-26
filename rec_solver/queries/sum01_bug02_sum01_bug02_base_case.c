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
n1 = Int("n1")
sn1 = Int("sn1")
sn2 = Function("sn2", IntSort(), IntSort())
sn3 = Int("sn3")
tmp1 = Int("tmp1")
s.add(tmp1 >= 0)
tmp0 = Int("tmp0")
s.add(i1 == tmp0)
s.add(n1 == tmp1)
s.add(sn1 == 0)
s.add(i2 == 0)
s.add(sn2(0) == sn1)
s.add(ForAll(n, Implies(n >= 0, sn2(n + 1) == If(i3(n) == 4, -10, sn2(n) + 2))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, sn2(n) == If(And(0 <= n, n < 4), 2*n, If(And(4 <= n, n < 5), 8, If(And(5 <= n, n < 5), -10, 2*n - 20))))))
#################################
s.add(sn3 == sn2(N0))
s.add(i3(0) == i2)
s.add(ForAll(n, Implies(n >= 0, i3(n + 1) == If(i3(n) == 4, i3(n) + 1, i3(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, i3(n) == If(And(0 <= n, n < 4), n, If(And(4 <= n, n < 5), 4, If(And(5 <= n, n < 5), n, n))))))
#################################
s.add(i4 == i3(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), i3(n) <= n1)))
s.add(Not(i3(N0) <= n1))
########## assert ##########
############################
