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
k1 = Int("k1")
k2 = Int("k2")
k3 = Function("k3", IntSort(), IntSort())
k4 = Int("k4")
LARGE_INT1 = Int("LARGE_INT1")
tmp3 = Int("tmp3")
s.add(tmp3 >= 0)
tmp1 = Int("tmp1")
tmp4 = Int("tmp4")
tmp2 = Int("tmp2")
tmp0 = Int("tmp0")
s.add(i1 == tmp0)
s.add(j1 == tmp1)
s.add(k1 == tmp2)
s.add(LARGE_INT1 == tmp3)
s.add(i2 == 1)
s.add(j2 == 1)
s.add(k2 == tmp4)
s.add(And(0 <= tmp4, tmp4 <= 1))
s.add(i3(0) == i2)
s.add(ForAll(n, Implies(n >= 0, i3(n + 1) == If(True, i3(n) + 1, i3(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, i3(n) == n + 1)))
#################################
s.add(i4 == i3(N0))
s.add(j3(0) == j2)
s.add(ForAll(n, Implies(n >= 0, j3(n + 1) == If(True, j3(n) + k3(n), j3(n) + k3(n)))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 2*j3(n) == 2*n*tmp4 - n*(n - 1) + 2)))
#################################
s.add(j4 == j3(N0))
s.add(k3(0) == k2)
s.add(ForAll(n, Implies(n >= 0, k3(n + 1) == If(True, k3(n) - 1, k3(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, k3(n) == -n + tmp4)))
#################################
s.add(k4 == k3(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), i3(n) < LARGE_INT1)))
s.add(Not(i3(N0) < LARGE_INT1))
########## assertion in loop ##########
