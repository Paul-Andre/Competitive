import random

n = 2000
m = 2000

a = 20

print(n,m);
for _ in range(n):
    print(" ".join([str(random.randint(1, a)) for _ in range(m)]))
