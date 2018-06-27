import random

t  = 100

print(t)
for _ in range(t):
    n = 10**5
    print(n)
    print(" ".join(str(random.randint(0,10**9)) for _ in range(n)))
