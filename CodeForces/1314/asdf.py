import random
n = 200000
aa = 4
tt = 10

print(n)
a = []
for _ in range(n):
    a.append( random.randint(1, aa))

print( " ".join(map(str, a)));
t = []
for _ in range(n):
    t.append( random.randint(1, tt))
print( " ".join(map(str, t)));
