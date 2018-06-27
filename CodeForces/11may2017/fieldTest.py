from random import *
from sys import *

n = 100
if (len(argv) >= 2) :
    n = int(argv[1])



print( randint(1, 100000), randint(1, 100000), randint(1, 10), randint(1, 10), n)

for i in range(n):
    print(randint(2, 5))

