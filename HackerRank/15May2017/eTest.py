import sys
import random

n = int(sys.argv[1])
m = int(sys.argv[2])

print(n,m)

print(" ".join([str(random.randint(1,m+10)) for _ in range(n)]))

print(" ".join([str(random.randint(1,2)) for _ in range(m)]))

for _ in range(n):
    print(" ".join([str(random.randint(1,10)) for _ in range(m)]))



