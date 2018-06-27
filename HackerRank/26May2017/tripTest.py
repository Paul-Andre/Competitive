from random import *
from sys import argv

n = 10
if ( len(argv) > 1) :
    n = int(argv[1])

q = 10
if ( len(argv) > 2) :
    q = int(argv[2])

w = 1000000

print(n,q)

print(" ".join([str(randint(1,w)) for _ in range(n-1)]))

for _ in range(n):
    print(randint(1,w), randint(1,w))

for _ in range (q):
    a = randint(1,n)
    b = randint(1,n)
    if (a>b):
        a,b = b,a

    print(a,b)
