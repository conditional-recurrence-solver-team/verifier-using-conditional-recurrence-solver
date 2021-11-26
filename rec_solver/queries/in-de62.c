from z3 import *
from aux_z3 import *
s = set()
n = Int("n")
N0 = Int("N0")
s.add(N0 >= 0)
N1 = Int("N1")
s.add(N1 >= 0)
N2 = Int("N2")
s.add(N2 >= 0)
N3 = Int("N3")
s.add(N3 >= 0)
N4 = Int("N4")
s.add(N4 >= 0)
N5 = Int("N5")
s.add(N5 >= 0)
solver = Solver()
solver.set("timeout", 2000)
n1 = Int("n1")
x1 = Int("x1")
x2 = Function("x2", IntSort(), IntSort())
x3 = Int("x3")
x4 = Function("x4", IntSort(), IntSort())
x5 = Int("x5")
x6 = Function("x6", IntSort(), IntSort())
x7 = Int("x7")
x8 = Function("x8", IntSort(), IntSort())
x9 = Int("x9")
x10 = Function("x10", IntSort(), IntSort())
x11 = Int("x11")
y1 = Int("y1")
y2 = Function("y2", IntSort(), IntSort())
y3 = Int("y3")
y4 = Function("y4", IntSort(), IntSort())
y5 = Int("y5")
y6 = Function("y6", IntSort(), IntSort())
y7 = Int("y7")
y8 = Function("y8", IntSort(), IntSort())
y9 = Int("y9")
z1 = Int("z1")
z2 = Int("z2")
z3 = Function("z3", IntSort(), IntSort())
z4 = Int("z4")
z5 = Function("z5", IntSort(), IntSort())
z6 = Int("z6")
z7 = Function("z7", IntSort(), IntSort())
z8 = Int("z8")
tmp1 = Int("tmp1")
tmp0 = Int("tmp0")
s.add(tmp0 >= 0)
s.add(n1 == tmp0)
s.add(x1 == tmp0)
s.add(y1 == 0)
s.add(z1 == tmp1)
s.add(x2(0) == x1)
s.add(ForAll(n, Implies(n >= 0, x2(n + 1) == If(True, x2(n) - 1, x2(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, x2(n) == -n + tmp0)))
#################################
s.add(x3 == x2(N0))
s.add(y2(0) == y1)
s.add(ForAll(n, Implies(n >= 0, y2(n + 1) == If(True, y2(n) + 1, y2(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, y2(n) == n)))
#################################
s.add(y3 == y2(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), x2(n) > 0)))
s.add(Not(x2(N0) > 0))
s.add(z2 == y3)
s.add(x4(0) == x3)
s.add(ForAll(n, Implies(n >= 0, x4(n + 1) == If(True, x4(n) + 1, x4(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, x4(n) == n + x3)))
#################################
s.add(x5 == x4(N1))
s.add(z3(0) == z2)
s.add(ForAll(n, Implies(n >= 0, z3(n + 1) == If(True, z3(n) - 1, z3(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, z3(n) == -n + y3)))
#################################
s.add(z4 == z3(N1))
s.add(ForAll(n, Implies(And(0 <= n, n < N1), z3(n) > 0)))
s.add(Not(z3(N1) > 0))
s.add(y4(0) == y3)
s.add(ForAll(n, Implies(n >= 0, y4(n + 1) == If(True, y4(n) - 1, y4(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, y4(n) == -n + y3)))
#################################
s.add(y5 == y4(N2))
s.add(z5(0) == z4)
s.add(ForAll(n, Implies(n >= 0, z5(n + 1) == If(True, z5(n) + 1, z5(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, z5(n) == n + z4)))
#################################
s.add(z6 == z5(N2))
s.add(ForAll(n, Implies(And(0 <= n, n < N2), y4(n) > 0)))
s.add(Not(y4(N2) > 0))
s.add(x6(0) == x5)
s.add(ForAll(n, Implies(n >= 0, x6(n + 1) == If(True, x6(n) - 1, x6(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, x6(n) == -n + x5)))
#################################
s.add(x7 == x6(N3))
s.add(y6(0) == y5)
s.add(ForAll(n, Implies(n >= 0, y6(n + 1) == If(True, y6(n) + 1, y6(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, y6(n) == n + y5)))
#################################
s.add(y7 == y6(N3))
s.add(ForAll(n, Implies(And(0 <= n, n < N3), x6(n) > 0)))
s.add(Not(x6(N3) > 0))
s.add(x8(0) == x7)
s.add(ForAll(n, Implies(n >= 0, x8(n + 1) == If(True, x8(n) + 1, x8(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, x8(n) == n + x7)))
#################################
s.add(x9 == x8(N4))
s.add(z7(0) == z6)
s.add(ForAll(n, Implies(n >= 0, z7(n + 1) == If(True, z7(n) - 1, z7(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, z7(n) == -n + z6)))
#################################
s.add(z8 == z7(N4))
s.add(ForAll(n, Implies(And(0 <= n, n < N4), z7(n) > 0)))
s.add(Not(z7(N4) > 0))
s.add(y8(0) == y7)
s.add(ForAll(n, Implies(n >= 0, y8(n + 1) == If(True, y8(n) - 1, y8(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, y8(n) == -n + y7)))
#################################
s.add(y9 == y8(N5))
s.add(x10(0) == x9)
s.add(ForAll(n, Implies(n >= 0, x10(n + 1) == If(True, x10(n) - 1, x10(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, x10(n) == -n + x9)))
#################################
s.add(x11 == x10(N5))
s.add(ForAll(n, Implies(And(0 <= n, n < N5), y8(n) > 0)))
s.add(Not(y8(N5) > 0))
########## assert ##########
############################
