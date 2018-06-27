import random

n = 10**5
q = 10**5

print(n,q);
for _ in range(n):
    print(random.choice([0,1,1]), end=" ");
print()

for i in range(2, n+1):
    print(random.randint(1,i-1), end=" ");
print()

for _ in range(q):
    good = False;
    while not good:
        c = random.choice("CTK");
        if c == "T":
            print(c, random.randint(1,n));
            good = True;
        if c == "K":
            print(c, random.randint(1,n),random.randint(1,n),random.randint(1,20));
            good = True;
        if c == "C":
            u = random.randint(1,n);
            v = random.randint(1,n);
            if (u == v):
                good = False
                continue;
            if (v>=u):
                u,v = v,u
            print(c, u, v);
            good = True

            
        
