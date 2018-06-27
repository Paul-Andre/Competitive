from random import *
n = 5000
q = 5000

m = 500

print(n,q)

print(" ".join([str(randint(1,m)) for _ in range(n)]))
for x in range(2,n+1):
    print(x, randint(1,x-1))

for _ in range(q):
    print(randint(1,n), randint(1,n), 1)
