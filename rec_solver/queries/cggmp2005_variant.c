from z3 import *
from aux_z3 import *
s = set()
n = Int("n")
N0 = Int("N0")
s.add(N0 >= 0)
solver = Solver()
solver.set("timeout", 2000)
lo1 = Int("lo1")
lo2 = Int("lo2")
lo3 = Function("lo3", IntSort(), IntSort())
lo4 = Int("lo4")
mid1 = Int("mid1")
mid2 = Int("mid2")
mid3 = Function("mid3", IntSort(), IntSort())
mid4 = Int("mid4")
hi1 = Int("hi1")
hi2 = Int("hi2")
hi3 = Function("hi3", IntSort(), IntSort())
hi4 = Int("hi4")
tmp1 = Int("tmp1")
tmp3 = Int("tmp3")
tmp2 = Int("tmp2")
tmp0 = Int("tmp0")
s.add(lo1 == tmp0)
s.add(mid1 == tmp1)
s.add(hi1 == tmp2)
s.add(lo2 == 0)
s.add(mid2 == tmp3)
s.add(tmp3 > 0)
s.add(hi2 == 2*tmp3)
s.add(lo3(0) == lo2)
s.add(ForAll(n, Implies(n >= 0, lo3(n + 1) == If(True, lo3(n) + 1, lo3(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, lo3(n) == n)))
#################################
s.add(lo4 == lo3(N0))
s.add(hi3(0) == hi2)
s.add(ForAll(n, Implies(n >= 0, hi3(n + 1) == If(True, hi3(n) - 1, hi3(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, hi3(n) == -n + 2*tmp3)))
#################################
s.add(hi4 == hi3(N0))
s.add(mid3(0) == mid2)
s.add(ForAll(n, Implies(n >= 0, mid3(n + 1) == If(True, mid3(n) - 1, mid3(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, mid3(n) == -n + tmp3)))
#################################
s.add(mid4 == mid3(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), mid3(n) > 0)))
s.add(Not(mid3(N0) > 0))
########## assert ##########
############################
