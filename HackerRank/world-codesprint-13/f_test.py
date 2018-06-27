import random
n = 10000
q = 10000
print(n)
e = []
for i in range(2, n+1):
    p = (i, random.randint(1, i-1))
    e.append(p)
    print(p[0], p[1])

print(q)
for _ in range(q):
    c = random.choice(["d","c","q"])
    if (c in "dc"):
        p = random.choice(e)
        print(c, p[0], p[1])
    else:
        print(c, random.randint(1, n), random.randint(1, n))

