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
sum1 = Int("sum1")
sum2 = Int("sum2")
sum3 = Function("sum3", IntSort(), IntSort())
sum4 = Int("sum4")
SIZE1 = Int("SIZE1")
tmp1 = Int("tmp1")
tmp0 = Int("tmp0")
s.add(i1 == tmp0)
s.add(SIZE1 == 40000)
s.add(sum1 == tmp1)
s.add(i2 == 0)
s.add(sum2 == 0)
s.add(i3(0) == i2)
s.add(ForAll(n, Implies(n >= 0, i3(n + 1) == If(True, i3(n) + 1, i3(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, i3(n) == n)))
#################################
s.add(i4 == i3(N0))
s.add(sum3(0) == sum2)
s.add(ForAll(n, Implies(n >= 0, sum3(n + 1) == If(True, i3(n) + sum3(n) + 1, i3(n) + sum3(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 2*sum3(n) == n*(n + 1))))
#################################
s.add(sum4 == sum3(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), i3(n) < SIZE1)))
s.add(Not(i3(N0) < SIZE1))
########## assert ##########
############################
