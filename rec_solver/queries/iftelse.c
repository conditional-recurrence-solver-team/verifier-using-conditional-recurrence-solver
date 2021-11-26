from z3 import *
from aux_z3 import *
s = set()
n = Int("n")
N0 = Int("N0")
s.add(N0 >= 0)
solver = Solver()
solver.set("timeout", 2000)
n1 = Int("n1")
SIZE1 = Int("SIZE1")
i1 = Int("i1")
i2 = Function("i2", IntSort(), IntSort())
i3 = Int("i3")
j1 = Int("j1")
j2 = Function("j2", IntSort(), IntSort())
j3 = Int("j3")
k1 = Int("k1")
k2 = Function("k2", IntSort(), IntSort())
k3 = Int("k3")
tmp0 = Int("tmp0")
s.add(tmp0 >= 0)
s.add(SIZE1 == 20000001)
s.add(n1 == tmp0)
s.add(i1 == 0)
s.add(j1 == 0)
s.add(k1 == 0)
s.add(tmp0 <= 20000001)
s.add(j2(0) == j1)
s.add(ForAll(n, Implies(n >= 0, j2(n + 1) == If(Mod(i2(n) + 1, 2) == 1, j2(n) + 3, j2(n)))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 2*j2(n) == If(Mod(n, 2) == 0, 3*n, 3*n + 3))))
#################################
s.add(j3 == j2(N0))
s.add(k2(0) == k1)
s.add(ForAll(n, Implies(n >= 0, k2(n + 1) == If(Mod(i2(n) + 1, 2) == 1, k2(n), k2(n) + 3))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 2*k2(n) == If(Mod(n, 2) == 0, 3*n, 3*n - 3))))
#################################
s.add(k3 == k2(N0))
s.add(i2(0) == i1)
s.add(ForAll(n, Implies(n >= 0, i2(n + 1) == If(Mod(i2(n) + 1, 2) == 1, i2(n) + 3, i2(n) + 3))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, i2(n) == If(Mod(n, 2) == 0, 3*n, 3*n))))
#################################
s.add(i3 == i2(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), i2(n) < n1)))
s.add(Not(i2(N0) < n1))
########## assertion in loop ##########
