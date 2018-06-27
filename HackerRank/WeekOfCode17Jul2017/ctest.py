import random

m = 10**9
n = 8000
q = 5*10**5


print(n,q)

print(" ".join([str(random.randint(1, m)) for _ in range(n)]))

for _ in range(q):
    print(random.randint(1, m), random.randint(1, m))
