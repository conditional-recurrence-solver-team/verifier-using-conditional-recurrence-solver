from z3 import *
from aux_z3 import *
s = set()
n = Int("n")
N0 = Int("N0")
s.add(N0 >= 0)
solver = Solver()
solver.set("timeout", 2000)
x1 = Int("x1")
x2 = Int("x2")
x3 = Function("x3", IntSort(), IntSort())
x4 = Int("x4")
y1 = Int("y1")
y2 = Int("y2")
y3 = Function("y3", IntSort(), IntSort())
y4 = Int("y4")
tmp1 = Int("tmp1")
tmp2 = Int("tmp2")
tmp0 = Int("tmp0")
s.add(x1 == tmp0)
s.add(y1 == tmp1)
s.add(x2 == -50)
s.add(y2 == tmp2)
s.add(x3(0) == x2)
s.add(ForAll(n, Implies(n >= 0, x3(n + 1) == If(True, x3(n) + y3(n), x3(n) + y3(n)))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, 2*x3(n) == 2*n*tmp2 + n*(n - 1) - 100)))
#################################
s.add(x4 == x3(N0))
s.add(y3(0) == y2)
s.add(ForAll(n, Implies(n >= 0, y3(n + 1) == If(True, y3(n) + 1, y3(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, y3(n) == n + tmp2)))
#################################
s.add(y4 == y3(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), x3(n) < 0)))
s.add(Not(x3(N0) < 0))
########## assert ##########
############################
