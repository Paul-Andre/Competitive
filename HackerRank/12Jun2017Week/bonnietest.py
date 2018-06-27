from random import *
from sys import *

n = int(argv[1])
m = int(argv[2])
q = int(argv[3])

print(n,m,q);

ex = set();

for _ in range(m):
    while(True) :
        u,v = randint(1, n), randint(1, n)
        if (u==v or (u,v) in ex) :
            continue
        ex.add((u,v));
        ex.add((v,u));
        print(u,v)
        break;


for _ in range(q):
    print(randint(1, n), randint(1, n), randint(1,n))
