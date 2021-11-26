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
v31 = Int("v31")
v32 = Function("v32", IntSort(), IntSort())
v33 = Int("v33")
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
s.add(SIZE1 == 20000001)
s.add(n1 == 0)
s.add(i1 == 0)
s.add(k1 == 0)
s.add(j1 == 0)
s.add(l1 == 0)
s.add(v31 == 0)
s.add(v41 == 0)
s.add(n2 == tmp0)
s.add(tmp0 <= 20000001)
s.add(v32(0) == v31)
s.add(ForAll(n, Implies(n >= 0, v32(n + 1) == If(Mod(l2(n), 5) == 0, v32(n) + 1, If(Mod(l2(n), 4) == 0, v32(n), If(Mod(l2(n), 3) == 0, v32(n), If(Mod(l2(n), 2) == 0, v32(n), v32(n))))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 20*v32(n) == If(And(0 <= n, n < 8), If(Mod(n, 8) == 0, 5*n, If(Mod(n, 8) == 1, 5*n + 15, If(Mod(n, 8) == 2, 5*n + 10, If(Mod(n, 8) == 3, 5*n + 5, If(Mod(n, 8) == 4, 5*n, If(Mod(n, 8) == 5, 5*n - 5, If(Mod(n, 8) == 6, 5*n + 10, 5*n + 5))))))), If(Mod(n, 60) == 0, 4*n, If(Mod(n, 60) == 1, 4*n + 16, If(Mod(n, 60) == 2, 4*n + 12, If(Mod(n, 60) == 3, 4*n + 8, If(Mod(n, 60) == 4, 4*n + 4, If(Mod(n, 60) == 5, 4*n, If(Mod(n, 60) == 6, 4*n + 16, If(Mod(n, 60) == 7, 4*n + 12, If(Mod(n, 60) == 8, 4*n + 8, If(Mod(n, 60) == 9, 4*n + 4, If(Mod(n, 60) == 10, 4*n, If(Mod(n, 60) == 11, 4*n + 16, If(Mod(n, 60) == 12, 4*n + 12, If(Mod(n, 60) == 13, 4*n + 8, If(Mod(n, 60) == 14, 4*n + 4, If(Mod(n, 60) == 15, 4*n, If(Mod(n, 60) == 16, 4*n + 16, If(Mod(n, 60) == 17, 4*n + 12, If(Mod(n, 60) == 18, 4*n + 8, If(Mod(n, 60) == 19, 4*n + 4, If(Mod(n, 60) == 20, 4*n, If(Mod(n, 60) == 21, 4*n + 16, If(Mod(n, 60) == 22, 4*n + 12, If(Mod(n, 60) == 23, 4*n + 8, If(Mod(n, 60) == 24, 4*n + 4, If(Mod(n, 60) == 25, 4*n, If(Mod(n, 60) == 26, 4*n + 16, If(Mod(n, 60) == 27, 4*n + 12, If(Mod(n, 60) == 28, 4*n + 8, If(Mod(n, 60) == 29, 4*n + 4, If(Mod(n, 60) == 30, 4*n, If(Mod(n, 60) == 31, 4*n + 16, If(Mod(n, 60) == 32, 4*n + 12, If(Mod(n, 60) == 33, 4*n + 8, If(Mod(n, 60) == 34, 4*n + 4, If(Mod(n, 60) == 35, 4*n, If(Mod(n, 60) == 36, 4*n + 16, If(Mod(n, 60) == 37, 4*n + 12, If(Mod(n, 60) == 38, 4*n + 8, If(Mod(n, 60) == 39, 4*n + 4, If(Mod(n, 60) == 40, 4*n, If(Mod(n, 60) == 41, 4*n + 16, If(Mod(n, 60) == 42, 4*n + 12, If(Mod(n, 60) == 43, 4*n + 8, If(Mod(n, 60) == 44, 4*n + 4, If(Mod(n, 60) == 45, 4*n, If(Mod(n, 60) == 46, 4*n + 16, If(Mod(n, 60) == 47, 4*n + 12, If(Mod(n, 60) == 48, 4*n + 8, If(Mod(n, 60) == 49, 4*n + 4, If(Mod(n, 60) == 50, 4*n, If(Mod(n, 60) == 51, 4*n + 16, If(Mod(n, 60) == 52, 4*n + 12, If(Mod(n, 60) == 53, 4*n + 8, If(Mod(n, 60) == 54, 4*n + 4, If(Mod(n, 60) == 55, 4*n, If(Mod(n, 60) == 56, 4*n + 16, If(Mod(n, 60) == 57, 4*n + 12, If(Mod(n, 60) == 58, 4*n + 8, 4*n + 4)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#################################
s.add(v33 == v32(N0))
s.add(l2(0) == l1)
s.add(ForAll(n, Implies(n >= 0, l2(n + 1) == If(Mod(l2(n), 5) == 0, l2(n) + 1, If(Mod(l2(n), 4) == 0, l2(n) + 1, If(Mod(l2(n), 3) == 0, l2(n) + 1, If(Mod(l2(n), 2) == 0, l2(n) + 1, l2(n) + 1)))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, l2(n) == If(And(0 <= n, n < 8), If(Mod(n, 8) == 0, n, If(Mod(n, 8) == 1, n, If(Mod(n, 8) == 2, n, If(Mod(n, 8) == 3, n, If(Mod(n, 8) == 4, n, If(Mod(n, 8) == 5, n, If(Mod(n, 8) == 6, n, n))))))), If(Mod(n, 60) == 0, n, If(Mod(n, 60) == 1, n, If(Mod(n, 60) == 2, n, If(Mod(n, 60) == 3, n, If(Mod(n, 60) == 4, n, If(Mod(n, 60) == 5, n, If(Mod(n, 60) == 6, n, If(Mod(n, 60) == 7, n, If(Mod(n, 60) == 8, n, If(Mod(n, 60) == 9, n, If(Mod(n, 60) == 10, n, If(Mod(n, 60) == 11, n, If(Mod(n, 60) == 12, n, If(Mod(n, 60) == 13, n, If(Mod(n, 60) == 14, n, If(Mod(n, 60) == 15, n, If(Mod(n, 60) == 16, n, If(Mod(n, 60) == 17, n, If(Mod(n, 60) == 18, n, If(Mod(n, 60) == 19, n, If(Mod(n, 60) == 20, n, If(Mod(n, 60) == 21, n, If(Mod(n, 60) == 22, n, If(Mod(n, 60) == 23, n, If(Mod(n, 60) == 24, n, If(Mod(n, 60) == 25, n, If(Mod(n, 60) == 26, n, If(Mod(n, 60) == 27, n, If(Mod(n, 60) == 28, n, If(Mod(n, 60) == 29, n, If(Mod(n, 60) == 30, n, If(Mod(n, 60) == 31, n, If(Mod(n, 60) == 32, n, If(Mod(n, 60) == 33, n, If(Mod(n, 60) == 34, n, If(Mod(n, 60) == 35, n, If(Mod(n, 60) == 36, n, If(Mod(n, 60) == 37, n, If(Mod(n, 60) == 38, n, If(Mod(n, 60) == 39, n, If(Mod(n, 60) == 40, n, If(Mod(n, 60) == 41, n, If(Mod(n, 60) == 42, n, If(Mod(n, 60) == 43, n, If(Mod(n, 60) == 44, n, If(Mod(n, 60) == 45, n, If(Mod(n, 60) == 46, n, If(Mod(n, 60) == 47, n, If(Mod(n, 60) == 48, n, If(Mod(n, 60) == 49, n, If(Mod(n, 60) == 50, n, If(Mod(n, 60) == 51, n, If(Mod(n, 60) == 52, n, If(Mod(n, 60) == 53, n, If(Mod(n, 60) == 54, n, If(Mod(n, 60) == 55, n, If(Mod(n, 60) == 56, n, If(Mod(n, 60) == 57, n, If(Mod(n, 60) == 58, n, n)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#################################
s.add(l3 == l2(N0))
s.add(j2(0) == j1)
s.add(ForAll(n, Implies(n >= 0, j2(n + 1) == If(Mod(l2(n), 5) == 0, j2(n), If(Mod(l2(n), 4) == 0, j2(n), If(Mod(l2(n), 3) == 0, j2(n), If(Mod(l2(n), 2) == 0, j2(n) + 1, j2(n))))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 120*j2(n) == If(And(0 <= n, n < 8), If(Mod(n, 8) == 0, 15*n, If(Mod(n, 8) == 1, 15*n - 15, If(Mod(n, 8) == 2, 15*n - 30, If(Mod(n, 8) == 3, 15*n + 75, If(Mod(n, 8) == 4, 15*n + 60, If(Mod(n, 8) == 5, 15*n + 45, If(Mod(n, 8) == 6, 15*n + 30, 15*n + 15))))))), If(Mod(n, 60) == 0, 16*n, If(Mod(n, 60) == 1, 16*n - 16, If(Mod(n, 60) == 2, 16*n - 32, If(Mod(n, 60) == 3, 16*n + 72, If(Mod(n, 60) == 4, 16*n + 56, If(Mod(n, 60) == 5, 16*n + 40, If(Mod(n, 60) == 6, 16*n + 24, If(Mod(n, 60) == 7, 16*n + 8, If(Mod(n, 60) == 8, 16*n - 8, If(Mod(n, 60) == 9, 16*n - 24, If(Mod(n, 60) == 10, 16*n - 40, If(Mod(n, 60) == 11, 16*n - 56, If(Mod(n, 60) == 12, 16*n - 72, If(Mod(n, 60) == 13, 16*n - 88, If(Mod(n, 60) == 14, 16*n - 104, If(Mod(n, 60) == 15, 16*n, If(Mod(n, 60) == 16, 16*n - 16, If(Mod(n, 60) == 17, 16*n - 32, If(Mod(n, 60) == 18, 16*n - 48, If(Mod(n, 60) == 19, 16*n - 64, If(Mod(n, 60) == 20, 16*n - 80, If(Mod(n, 60) == 21, 16*n - 96, If(Mod(n, 60) == 22, 16*n - 112, If(Mod(n, 60) == 23, 16*n - 8, If(Mod(n, 60) == 24, 16*n - 24, If(Mod(n, 60) == 25, 16*n - 40, If(Mod(n, 60) == 26, 16*n - 56, If(Mod(n, 60) == 27, 16*n + 48, If(Mod(n, 60) == 28, 16*n + 32, If(Mod(n, 60) == 29, 16*n + 16, If(Mod(n, 60) == 30, 16*n, If(Mod(n, 60) == 31, 16*n - 16, If(Mod(n, 60) == 32, 16*n - 32, If(Mod(n, 60) == 33, 16*n - 48, If(Mod(n, 60) == 34, 16*n - 64, If(Mod(n, 60) == 35, 16*n + 40, If(Mod(n, 60) == 36, 16*n + 24, If(Mod(n, 60) == 37, 16*n + 8, If(Mod(n, 60) == 38, 16*n - 8, If(Mod(n, 60) == 39, 16*n + 96, If(Mod(n, 60) == 40, 16*n + 80, If(Mod(n, 60) == 41, 16*n + 64, If(Mod(n, 60) == 42, 16*n + 48, If(Mod(n, 60) == 43, 16*n + 32, If(Mod(n, 60) == 44, 16*n + 16, If(Mod(n, 60) == 45, 16*n, If(Mod(n, 60) == 46, 16*n - 16, If(Mod(n, 60) == 47, 16*n + 88, If(Mod(n, 60) == 48, 16*n + 72, If(Mod(n, 60) == 49, 16*n + 56, If(Mod(n, 60) == 50, 16*n + 40, If(Mod(n, 60) == 51, 16*n + 24, If(Mod(n, 60) == 52, 16*n + 8, If(Mod(n, 60) == 53, 16*n - 8, If(Mod(n, 60) == 54, 16*n - 24, If(Mod(n, 60) == 55, 16*n - 40, If(Mod(n, 60) == 56, 16*n - 56, If(Mod(n, 60) == 57, 16*n - 72, If(Mod(n, 60) == 58, 16*n - 88, 16*n + 16)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#################################
s.add(j3 == j2(N0))
s.add(v42(0) == v41)
s.add(ForAll(n, Implies(n >= 0, v42(n + 1) == If(Mod(l2(n), 5) == 0, v42(n), If(Mod(l2(n), 4) == 0, v42(n) + 1, If(Mod(l2(n), 3) == 0, v42(n), If(Mod(l2(n), 2) == 0, v42(n), v42(n))))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 40*v42(n) == If(And(0 <= n, n < 8), If(Mod(n, 8) == 0, 5*n, If(Mod(n, 8) == 1, 5*n - 5, If(Mod(n, 8) == 2, 5*n - 10, If(Mod(n, 8) == 3, 5*n - 15, If(Mod(n, 8) == 4, 5*n - 20, If(Mod(n, 8) == 5, 5*n + 15, If(Mod(n, 8) == 6, 5*n + 10, 5*n + 5))))))), If(Mod(n, 60) == 0, 8*n, If(Mod(n, 60) == 1, 8*n - 8, If(Mod(n, 60) == 2, 8*n - 16, If(Mod(n, 60) == 3, 8*n - 24, If(Mod(n, 60) == 4, 8*n - 32, If(Mod(n, 60) == 5, 8*n, If(Mod(n, 60) == 6, 8*n - 8, If(Mod(n, 60) == 7, 8*n - 16, If(Mod(n, 60) == 8, 8*n - 24, If(Mod(n, 60) == 9, 8*n + 8, If(Mod(n, 60) == 10, 8*n, If(Mod(n, 60) == 11, 8*n - 8, If(Mod(n, 60) == 12, 8*n - 16, If(Mod(n, 60) == 13, 8*n + 16, If(Mod(n, 60) == 14, 8*n + 8, If(Mod(n, 60) == 15, 8*n, If(Mod(n, 60) == 16, 8*n - 8, If(Mod(n, 60) == 17, 8*n + 24, If(Mod(n, 60) == 18, 8*n + 16, If(Mod(n, 60) == 19, 8*n + 8, If(Mod(n, 60) == 20, 8*n, If(Mod(n, 60) == 21, 8*n - 8, If(Mod(n, 60) == 22, 8*n - 16, If(Mod(n, 60) == 23, 8*n - 24, If(Mod(n, 60) == 24, 8*n - 32, If(Mod(n, 60) == 25, 8*n, If(Mod(n, 60) == 26, 8*n - 8, If(Mod(n, 60) == 27, 8*n - 16, If(Mod(n, 60) == 28, 8*n - 24, If(Mod(n, 60) == 29, 8*n + 8, If(Mod(n, 60) == 30, 8*n, If(Mod(n, 60) == 31, 8*n - 8, If(Mod(n, 60) == 32, 8*n - 16, If(Mod(n, 60) == 33, 8*n + 16, If(Mod(n, 60) == 34, 8*n + 8, If(Mod(n, 60) == 35, 8*n, If(Mod(n, 60) == 36, 8*n - 8, If(Mod(n, 60) == 37, 8*n + 24, If(Mod(n, 60) == 38, 8*n + 16, If(Mod(n, 60) == 39, 8*n + 8, If(Mod(n, 60) == 40, 8*n, If(Mod(n, 60) == 41, 8*n - 8, If(Mod(n, 60) == 42, 8*n - 16, If(Mod(n, 60) == 43, 8*n - 24, If(Mod(n, 60) == 44, 8*n - 32, If(Mod(n, 60) == 45, 8*n, If(Mod(n, 60) == 46, 8*n - 8, If(Mod(n, 60) == 47, 8*n - 16, If(Mod(n, 60) == 48, 8*n - 24, If(Mod(n, 60) == 49, 8*n + 8, If(Mod(n, 60) == 50, 8*n, If(Mod(n, 60) == 51, 8*n - 8, If(Mod(n, 60) == 52, 8*n - 16, If(Mod(n, 60) == 53, 8*n + 16, If(Mod(n, 60) == 54, 8*n + 8, If(Mod(n, 60) == 55, 8*n, If(Mod(n, 60) == 56, 8*n - 8, If(Mod(n, 60) == 57, 8*n + 24, If(Mod(n, 60) == 58, 8*n + 16, 8*n + 8)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#################################
s.add(v43 == v42(N0))
s.add(i2(0) == i1)
s.add(ForAll(n, Implies(n >= 0, i2(n + 1) == If(Mod(l2(n), 5) == 0, i2(n), If(Mod(l2(n), 4) == 0, i2(n), If(Mod(l2(n), 3) == 0, i2(n) + 1, If(Mod(l2(n), 2) == 0, i2(n), i2(n))))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 20*i2(n) == If(And(0 <= n, n < 8), If(Mod(n, 8) == 0, 5*n, If(Mod(n, 8) == 1, 5*n - 5, If(Mod(n, 8) == 2, 5*n - 10, If(Mod(n, 8) == 3, 5*n - 15, If(Mod(n, 8) == 4, 5*n, If(Mod(n, 8) == 5, 5*n - 5, If(Mod(n, 8) == 6, 5*n - 10, 5*n + 5))))))), If(Mod(n, 60) == 0, 4*n, If(Mod(n, 60) == 1, 4*n - 4, If(Mod(n, 60) == 2, 4*n - 8, If(Mod(n, 60) == 3, 4*n - 12, If(Mod(n, 60) == 4, 4*n + 4, If(Mod(n, 60) == 5, 4*n, If(Mod(n, 60) == 6, 4*n - 4, If(Mod(n, 60) == 7, 4*n + 12, If(Mod(n, 60) == 8, 4*n + 8, If(Mod(n, 60) == 9, 4*n + 4, If(Mod(n, 60) == 10, 4*n + 20, If(Mod(n, 60) == 11, 4*n + 16, If(Mod(n, 60) == 12, 4*n + 12, If(Mod(n, 60) == 13, 4*n + 8, If(Mod(n, 60) == 14, 4*n + 4, If(Mod(n, 60) == 15, 4*n, If(Mod(n, 60) == 16, 4*n - 4, If(Mod(n, 60) == 17, 4*n - 8, If(Mod(n, 60) == 18, 4*n - 12, If(Mod(n, 60) == 19, 4*n + 4, If(Mod(n, 60) == 20, 4*n, If(Mod(n, 60) == 21, 4*n - 4, If(Mod(n, 60) == 22, 4*n + 12, If(Mod(n, 60) == 23, 4*n + 8, If(Mod(n, 60) == 24, 4*n + 4, If(Mod(n, 60) == 25, 4*n, If(Mod(n, 60) == 26, 4*n - 4, If(Mod(n, 60) == 27, 4*n - 8, If(Mod(n, 60) == 28, 4*n + 8, If(Mod(n, 60) == 29, 4*n + 4, If(Mod(n, 60) == 30, 4*n, If(Mod(n, 60) == 31, 4*n - 4, If(Mod(n, 60) == 32, 4*n - 8, If(Mod(n, 60) == 33, 4*n - 12, If(Mod(n, 60) == 34, 4*n + 4, If(Mod(n, 60) == 35, 4*n, If(Mod(n, 60) == 36, 4*n - 4, If(Mod(n, 60) == 37, 4*n - 8, If(Mod(n, 60) == 38, 4*n - 12, If(Mod(n, 60) == 39, 4*n - 16, If(Mod(n, 60) == 40, 4*n, If(Mod(n, 60) == 41, 4*n - 4, If(Mod(n, 60) == 42, 4*n - 8, If(Mod(n, 60) == 43, 4*n + 8, If(Mod(n, 60) == 44, 4*n + 4, If(Mod(n, 60) == 45, 4*n, If(Mod(n, 60) == 46, 4*n - 4, If(Mod(n, 60) == 47, 4*n - 8, If(Mod(n, 60) == 48, 4*n - 12, If(Mod(n, 60) == 49, 4*n - 16, If(Mod(n, 60) == 50, 4*n - 20, If(Mod(n, 60) == 51, 4*n - 24, If(Mod(n, 60) == 52, 4*n - 8, If(Mod(n, 60) == 53, 4*n - 12, If(Mod(n, 60) == 54, 4*n - 16, If(Mod(n, 60) == 55, 4*n, If(Mod(n, 60) == 56, 4*n - 4, If(Mod(n, 60) == 57, 4*n - 8, If(Mod(n, 60) == 58, 4*n + 8, 4*n + 4)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#################################
s.add(i3 == i2(N0))
s.add(k2(0) == k1)
s.add(ForAll(n, Implies(n >= 0, k2(n + 1) == If(Mod(l2(n), 5) == 0, k2(n), If(Mod(l2(n), 4) == 0, k2(n), If(Mod(l2(n), 3) == 0, k2(n), If(Mod(l2(n), 2) == 0, k2(n), k2(n) + 1)))))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 60*k2(n) == If(And(0 <= n, n < 8), If(Mod(n, 8) == 0, 15*n, If(Mod(n, 8) == 1, 15*n - 15, If(Mod(n, 8) == 2, 15*n + 30, If(Mod(n, 8) == 3, 15*n + 15, If(Mod(n, 8) == 4, 15*n, If(Mod(n, 8) == 5, 15*n - 15, If(Mod(n, 8) == 6, 15*n - 30, 15*n - 45))))))), If(Mod(n, 60) == 0, 16*n, If(Mod(n, 60) == 1, 16*n - 16, If(Mod(n, 60) == 2, 16*n + 28, If(Mod(n, 60) == 3, 16*n + 12, If(Mod(n, 60) == 4, 16*n - 4, If(Mod(n, 60) == 5, 16*n - 20, If(Mod(n, 60) == 6, 16*n - 36, If(Mod(n, 60) == 7, 16*n - 52, If(Mod(n, 60) == 8, 16*n - 8, If(Mod(n, 60) == 9, 16*n - 24, If(Mod(n, 60) == 10, 16*n - 40, If(Mod(n, 60) == 11, 16*n - 56, If(Mod(n, 60) == 12, 16*n - 12, If(Mod(n, 60) == 13, 16*n - 28, If(Mod(n, 60) == 14, 16*n + 16, If(Mod(n, 60) == 15, 16*n, If(Mod(n, 60) == 16, 16*n - 16, If(Mod(n, 60) == 17, 16*n - 32, If(Mod(n, 60) == 18, 16*n + 12, If(Mod(n, 60) == 19, 16*n - 4, If(Mod(n, 60) == 20, 16*n + 40, If(Mod(n, 60) == 21, 16*n + 24, If(Mod(n, 60) == 22, 16*n + 8, If(Mod(n, 60) == 23, 16*n - 8, If(Mod(n, 60) == 24, 16*n + 36, If(Mod(n, 60) == 25, 16*n + 20, If(Mod(n, 60) == 26, 16*n + 4, If(Mod(n, 60) == 27, 16*n - 12, If(Mod(n, 60) == 28, 16*n - 28, If(Mod(n, 60) == 29, 16*n - 44, If(Mod(n, 60) == 30, 16*n, If(Mod(n, 60) == 31, 16*n - 16, If(Mod(n, 60) == 32, 16*n + 28, If(Mod(n, 60) == 33, 16*n + 12, If(Mod(n, 60) == 34, 16*n - 4, If(Mod(n, 60) == 35, 16*n - 20, If(Mod(n, 60) == 36, 16*n - 36, If(Mod(n, 60) == 37, 16*n - 52, If(Mod(n, 60) == 38, 16*n - 8, If(Mod(n, 60) == 39, 16*n - 24, If(Mod(n, 60) == 40, 16*n - 40, If(Mod(n, 60) == 41, 16*n - 56, If(Mod(n, 60) == 42, 16*n - 12, If(Mod(n, 60) == 43, 16*n - 28, If(Mod(n, 60) == 44, 16*n + 16, If(Mod(n, 60) == 45, 16*n, If(Mod(n, 60) == 46, 16*n - 16, If(Mod(n, 60) == 47, 16*n - 32, If(Mod(n, 60) == 48, 16*n + 12, If(Mod(n, 60) == 49, 16*n - 4, If(Mod(n, 60) == 50, 16*n + 40, If(Mod(n, 60) == 51, 16*n + 24, If(Mod(n, 60) == 52, 16*n + 8, If(Mod(n, 60) == 53, 16*n - 8, If(Mod(n, 60) == 54, 16*n + 36, If(Mod(n, 60) == 55, 16*n + 20, If(Mod(n, 60) == 56, 16*n + 4, If(Mod(n, 60) == 57, 16*n - 12, If(Mod(n, 60) == 58, 16*n - 28, 16*n - 44)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#################################
s.add(k3 == k2(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), l2(n) < n2)))
s.add(Not(l2(N0) < n2))
########## assert ##########
############################
