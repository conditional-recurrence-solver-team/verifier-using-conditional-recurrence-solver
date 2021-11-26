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
sn1 = Int("sn1")
sn2 = Function("sn2", IntSort(), IntSort())
sn3 = Int("sn3")
loop11 = Int("loop11")
n11 = Int("n11")
tmp1 = Int("tmp1")
s.add(tmp1 >= 0)
tmp0 = Int("tmp0")
s.add(tmp0 >= 0)
s.add(sn1 == 0)
s.add(loop11 == tmp0)
s.add(n11 == tmp1)
s.add(x1 == 0)
s.add(sn2(0) == sn1)
s.add(ForAll(n, Implies(n >= 0, sn2(n + 1) == If(x2(n) < 10, sn2(n) + 2, sn2(n)))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, sn2(n) == If(And(0 <= n, n < 10), 2*n, 20))))
#################################
s.add(sn3 == sn2(N0))
s.add(x2(0) == x1)
s.add(ForAll(n, Implies(n >= 0, x2(n + 1) == If(x2(n) < 10, x2(n) + 1, x2(n) + 1))))
########## closed form ##########
s.add(ForAll(n, Implies(n >= 0, x2(n) == If(And(0 <= n, n < 10), n, n))))
#################################
s.add(x3 == x2(N0))
s.add(ForAll(n, Implies(And(0 <= n, n < N0), True)))
########## assertion in loop ##########
