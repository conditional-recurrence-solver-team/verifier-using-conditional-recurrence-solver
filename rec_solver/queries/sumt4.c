from z3 import *
from aux_z3 import *
s = set()
n = Int("n")
N0 = Int("N0")
s.add(N0 >= 0)
solver = Solver()
solver.set("timeout", 2000)
n1 = Int("n1")
n2 = Int("n2")
SIZE1 = Int("SIZE1")
l1 = Int("l1")
l2 = Function("l2", IntSort(), IntSort())
l3 = Int("l3")
v41 = Int("v41")
v42 = Function("v42", IntSort(), IntSort())
v43 = Int("v43")
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
s.add(n1 == 0)
s.add(i1 == 0)
s.add(k1 == 0)
s.add(j1 == 0)
s.add(l1 == 0)
s.add(v41 == 0)
s.add(n2 == tmp0)
s.add(tmp0 <= 20000001)
s.add(v42(0) == v41)
s.add(ForAll(n, Implies(n >= 0, v42(n + 1) == If(Mod(l2(n), 4) == 0, v42(n) + 1, If(Mod(l2(n), 3) == 0, v42(n), If(Mod(l2(n), 2) == 0, v42(n), v42(n)))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 4*v42(n) == If(And(0 <= n, n < 8), If(Mod(n, 8) == 0, n, If(Mod(n, 8) == 1, n + 3, If(Mod(n, 8) == 2, n + 2, If(Mod(n, 8) == 3, n + 1, If(Mod(n, 8) == 4, n, If(Mod(n, 8) == 5, n + 3, If(Mod(n, 8) == 6, n + 2, n + 1))))))), If(Mod(n, 12) == 0, n, If(Mod(n, 12) == 1, n + 3, If(Mod(n, 12) == 2, n + 2, If(Mod(n, 12) == 3, n + 1, If(Mod(n, 12) == 4, n, If(Mod(n, 12) == 5, n + 3, If(Mod(n, 12) == 6, n + 2, If(Mod(n, 12) == 7, n + 1, If(Mod(n, 12) == 8, n, If(Mod(n, 12) == 9, n + 3, If(Mod(n, 12) == 10, n + 2, n + 1)))))))))))))))
#################################
s.add(v43 == v42(N0))
s.add(l2(0) == l1)
s.add(ForAll(n, Implies(n >= 0, l2(n + 1) == If(Mod(l2(n), 4) == 0, l2(n) + 1, If(Mod(l2(n), 3) == 0, l2(n) + 1, If(Mod(l2(n), 2) == 0, l2(n) + 1, l2(n) + 1))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, l2(n) == If(And(0 <= n, n < 8), If(Mod(n, 8) == 0, n, If(Mod(n, 8) == 1, n, If(Mod(n, 8) == 2, n, If(Mod(n, 8) == 3, n, If(Mod(n, 8) == 4, n, If(Mod(n, 8) == 5, n, If(Mod(n, 8) == 6, n, n))))))), If(Mod(n, 12) == 0, n, If(Mod(n, 12) == 1, n, If(Mod(n, 12) == 2, n, If(Mod(n, 12) == 3, n, If(Mod(n, 12) == 4, n, If(Mod(n, 12) == 5, n, If(Mod(n, 12) == 6, n, If(Mod(n, 12) == 7, n, If(Mod(n, 12) == 8, n, If(Mod(n, 12) == 9, n, If(Mod(n, 12) == 10, n, n)))))))))))))))
#################################
s.add(l3 == l2(N0))
s.add(j2(0) == j1)
s.add(ForAll(n, Implies(n >= 0, j2(n + 1) == If(Mod(l2(n), 4) == 0, j2(n), If(Mod(l2(n), 3) == 0, j2(n), If(Mod(l2(n), 2) == 0, j2(n) + 1, j2(n)))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 24*j2(n) == If(And(0 <= n, n < 8), If(Mod(n, 8) == 0, 3*n, If(Mod(n, 8) == 1, 3*n - 3, If(Mod(n, 8) == 2, 3*n - 6, If(Mod(n, 8) == 3, 3*n + 15, If(Mod(n, 8) == 4, 3*n + 12, If(Mod(n, 8) == 5, 3*n + 9, If(Mod(n, 8) == 6, 3*n + 6, 3*n + 3))))))), If(Mod(n, 12) == 0, 4*n, If(Mod(n, 12) == 1, 4*n - 4, If(Mod(n, 12) == 2, 4*n - 8, If(Mod(n, 12) == 3, 4*n + 12, If(Mod(n, 12) == 4, 4*n + 8, If(Mod(n, 12) == 5, 4*n + 4, If(Mod(n, 12) == 6, 4*n, If(Mod(n, 12) == 7, 4*n - 4, If(Mod(n, 12) == 8, 4*n - 8, If(Mod(n, 12) == 9, 4*n - 12, If(Mod(n, 12) == 10, 4*n - 16, 4*n + 4)))))))))))))))
#################################
s.add(j3 == j2(N0))
s.add(i2(0) == i1)
s.add(ForAll(n, Implies(n >= 0, i2(n + 1) == If(Mod(l2(n), 4) == 0, i2(n), If(Mod(l2(n), 3) == 0, i2(n) + 1, If(Mod(l2(n), 2) == 0, i2(n), i2(n)))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 4*i2(n) == If(And(0 <= n, n < 8), If(Mod(n, 8) == 0, n, If(Mod(n, 8) == 1, n - 1, If(Mod(n, 8) == 2, n - 2, If(Mod(n, 8) == 3, n - 3, If(Mod(n, 8) == 4, n, If(Mod(n, 8) == 5, n - 1, If(Mod(n, 8) == 6, n - 2, n + 1))))))), If(Mod(n, 12) == 0, n, If(Mod(n, 12) == 1, n - 1, If(Mod(n, 12) == 2, n - 2, If(Mod(n, 12) == 3, n - 3, If(Mod(n, 12) == 4, n, If(Mod(n, 12) == 5, n - 1, If(Mod(n, 12) == 6, n - 2, If(Mod(n, 12) == 7, n + 1, If(Mod(n, 12) == 8, n, If(Mod(n, 12) == 9, n - 1, If(Mod(n, 12) == 10, n + 2, n + 1)))))))))))))))
#################################
s.add(i3 == i2(N0))
s.add(k2(0) == k1)
s.add(ForAll(n, Implies(n >= 0, k2(n + 1) == If(Mod(l2(n), 4) == 0, k2(n), If(Mod(l2(n), 3) == 0, k2(n), If(Mod(l2(n), 2) == 0, k2(n), k2(n) + 1))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 24*k2(n) == If(And(0 <= n, n < 8), If(Mod(n, 8) == 0, 9*n, If(Mod(n, 8) == 1, 9*n - 9, If(Mod(n, 8) == 2, 9*n + 6, If(Mod(n, 8) == 3, 9*n - 3, If(Mod(n, 8) == 4, 9*n - 12, If(Mod(n, 8) == 5, 9*n - 21, If(Mod(n, 8) == 6, 9*n - 6, 9*n - 15))))))), If(Mod(n, 12) == 0, 8*n, If(Mod(n, 12) == 1, 8*n - 8, If(Mod(n, 12) == 2, 8*n + 8, If(Mod(n, 12) == 3, 8*n, If(Mod(n, 12) == 4, 8*n - 8, If(Mod(n, 12) == 5, 8*n - 16, If(Mod(n, 12) == 6, 8*n, If(Mod(n, 12) == 7, 8*n - 8, If(Mod(n, 12) == 8, 8*n + 8, If(Mod(n, 12) == 9, 8*n, If(Mod(n, 12) == 10, 8*n - 8, 8*n - 16)))))))))))))))
#################################
s.add(k3 == k2(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), l2(n) < n2)))
s.add(Not(l2(N0) < n2))
########## assert ##########
############################
