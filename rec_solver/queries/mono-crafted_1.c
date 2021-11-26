from z3 import *
from aux_z3 import *
s = set()
n = Int("n")
N0 = Int("N0")
s.add(N0 >= 0)
N1 = Int("N1")
s.add(N1 >= 0)
solver = Solver()
solver.set("timeout", 2000)
x1 = Int("x1")
x2 = Int("x2")
x3 = Function("x3", IntSort(), IntSort())
x4 = Int("x4")
x5 = Function("x5", IntSort(), IntSort())
x6 = Int("x6")
y1 = Int("y1")
y2 = Function("y2", IntSort(), IntSort())
y3 = Int("y3")
y4 = Function("y4", IntSort(), IntSort())
y5 = Int("y5")
z1 = Int("z1")
s.add(x1 == 0)
s.add(y1 == 50000)
s.add(z1 == 0)
s.add(x2 == 0)
s.add(x3(0) == x2)
s.add(ForAll(n, Implies(n >= 0, x3(n + 1) == If(x3(n) < 50000, x3(n) + 1, x3(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, x3(n) == If(And(0 <= n, n < 50000), n, n))))
#################################
s.add(x4 == x3(N0))
s.add(y2(0) == y1)
s.add(ForAll(n, Implies(n >= 0, y2(n + 1) == If(x3(n) < 50000, y2(n), y2(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, y2(n) == If(And(0 <= n, n < 50000), 50000, n))))
#################################
s.add(y3 == y2(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), x3(n) < 1000000)))
s.add(Not(x3(N0) < 1000000))
s.add(y4(0) == y3)
s.add(ForAll(n, Implies(n >= 0, y4(n + 1) == If(True, y4(n) - 1, y4(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, y4(n) == -n + y3)))
#################################
s.add(y5 == y4(N1))
s.add(x5(0) == x4)
s.add(ForAll(n, Implies(n >= 0, x5(n + 1) == If(True, x5(n) - 1, x5(n) - 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, x5(n) == -n + x4)))
#################################
s.add(x6 == x5(N1))
s.add(ForAll(n, Implies(And(0 <= n, n < N1), y4(n) > z1)))
s.add(Not(y4(N1) > z1))
########## assert ##########
############################
