from sys import *
from random import *

n = int(argv[1])
q = int(argv[2])
#alpha = "abcdefghijklmnop"
alpha = "abcaae" #efghijklmnop"

m = 100

print(n,q);
print("".join([choice(alpha) for _ in range(n) ]))
print("".join([choice(alpha) for _ in range(m) ]))

for i in range(2, n+1):
    print(randint(1, i-1), i)

for _ in range(q):
    print(randint(1, n), randint(1, n))
