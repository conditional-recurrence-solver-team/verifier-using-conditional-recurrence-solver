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
l1 = Int("l1")
l2 = Function("l2", IntSort(), IntSort())
l3 = Int("l3")
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
s.add(l1 == 0)
s.add(tmp0 <= 20000001)
s.add(i2(0) == i1)
s.add(ForAll(n, Implies(n >= 0, i2(n + 1) == If(Mod(l2(n), 3) == 0, i2(n) + 1, If(Mod(l2(n), 2) == 0, i2(n), i2(n))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 6*i2(n) == If(And(0 <= n, n < 4), If(Mod(n, 4) == 0, 3*n, If(Mod(n, 4) == 1, 3*n + 3, If(Mod(n, 4) == 2, 3*n, 3*n - 3))), If(Mod(n, 6) == 0, 2*n, If(Mod(n, 6) == 1, 2*n + 4, If(Mod(n, 6) == 2, 2*n + 2, If(Mod(n, 6) == 3, 2*n, If(Mod(n, 6) == 4, 2*n + 4, 2*n + 2)))))))))
#################################
s.add(i3 == i2(N0))
s.add(l2(0) == l1)
s.add(ForAll(n, Implies(n >= 0, l2(n + 1) == If(Mod(l2(n), 3) == 0, l2(n) + 1, If(Mod(l2(n), 2) == 0, l2(n) + 1, l2(n) + 1)))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, l2(n) == If(And(0 <= n, n < 4), If(Mod(n, 4) == 0, n, If(Mod(n, 4) == 1, n, If(Mod(n, 4) == 2, n, n))), If(Mod(n, 6) == 0, n, If(Mod(n, 6) == 1, n, If(Mod(n, 6) == 2, n, If(Mod(n, 6) == 3, n, If(Mod(n, 6) == 4, n, n)))))))))
#################################
s.add(l3 == l2(N0))
s.add(k2(0) == k1)
s.add(ForAll(n, Implies(n >= 0, k2(n + 1) == If(Mod(l2(n), 3) == 0, k2(n), If(Mod(l2(n), 2) == 0, k2(n), k2(n) + 1)))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 12*k2(n) == If(And(0 <= n, n < 4), If(Mod(n, 4) == 0, 3*n, If(Mod(n, 4) == 1, 3*n - 3, If(Mod(n, 4) == 2, 3*n + 6, 3*n + 3))), If(Mod(n, 6) == 0, 4*n, If(Mod(n, 6) == 1, 4*n - 4, If(Mod(n, 6) == 2, 4*n + 4, If(Mod(n, 6) == 3, 4*n, If(Mod(n, 6) == 4, 4*n - 4, 4*n - 8)))))))))
#################################
s.add(k3 == k2(N0))
s.add(j2(0) == j1)
s.add(ForAll(n, Implies(n >= 0, j2(n + 1) == If(Mod(l2(n), 3) == 0, j2(n), If(Mod(l2(n), 2) == 0, j2(n) + 1, j2(n))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 12*j2(n) == If(And(0 <= n, n < 4), If(Mod(n, 4) == 0, 3*n, If(Mod(n, 4) == 1, 3*n - 3, If(Mod(n, 4) == 2, 3*n - 6, 3*n + 3))), If(Mod(n, 6) == 0, 4*n, If(Mod(n, 6) == 1, 4*n - 4, If(Mod(n, 6) == 2, 4*n - 8, If(Mod(n, 6) == 3, 4*n, If(Mod(n, 6) == 4, 4*n - 4, 4*n + 4)))))))))
#################################
s.add(j3 == j2(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), l2(n) < n1)))
s.add(Not(l2(N0) < n1))
########## assert ##########
############################
