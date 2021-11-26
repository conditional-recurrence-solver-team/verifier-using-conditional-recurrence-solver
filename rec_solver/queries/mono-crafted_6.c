from z3 import *
from aux_z3 import *
s = set()
n = Int("n")
N0 = Int("N0")
s.add(N0 >= 0)
solver = Solver()
solver.set("timeout", 2000)
x1 = Int("x1")
x2 = Function("x2", IntSort(), IntSort())
x3 = Int("x3")
y1 = Int("y1")
y2 = Function("y2", IntSort(), IntSort())
y3 = Int("y3")
z1 = Int("z1")
s.add(x1 == 0)
s.add(y1 == 500000)
s.add(z1 == 0)
s.add(x2(0) == x1)
s.add(ForAll(n, Implies(n >= 0, x2(n + 1) == If(x2(n) < 500000, x2(n) + 1, If(x2(n) < 750000, x2(n) + 1, x2(n) + 2)))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, x2(n) == If(And(0 <= n, n < 500000), n, If(And(500000 <= n, n < 750000), n, 2*n - 750000)))))
#################################
s.add(x3 == x2(N0))
s.add(y2(0) == y1)
s.add(ForAll(n, Implies(n >= 0, y2(n + 1) == If(x2(n) < 500000, y2(n), If(x2(n) < 750000, y2(n) + 1, y2(n) + 1)))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, y2(n) == If(And(0 <= n, n < 500000), 500000, If(And(500000 <= n, n < 750000), n, n)))))
#################################
s.add(y3 == y2(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), x2(n) < 1000000)))
s.add(Not(x2(N0) < 1000000))
########## assert ##########
############################
