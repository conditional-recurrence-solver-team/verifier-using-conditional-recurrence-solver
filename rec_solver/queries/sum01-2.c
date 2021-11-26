from z3 import *
from aux_z3 import *
s = set()
n = Int("n")
solver = Solver()
solver.set("timeout", 2000)
n1 = Int("n1")
i1 = Int("i1")
sn1 = Int("sn1")
tmp1 = Int("tmp1")
tmp0 = Int("tmp0")
s.add(i1 == tmp0)
s.add(n1 == tmp1)
s.add(sn1 == 0)
s.add(And(tmp1 >= -1000, tmp1 < 1000))
########## assert ##########
############################
