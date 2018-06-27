import random
import string
import sys
n = int(sys.argv[1])
m = int(sys.argv[2])
q = int(sys.argv[3])
k = int(sys.argv[4])

if len(sys.argv)>=6:
    dig = sys.argv[5]
else:
    dig = string.ascii_letters

print(n,m,q,k)
st = ''.join(random.choice(dig) for _ in range(n))
print( st)
for _ in range(0,m):
    l = random.randint(0,k-1);
    r = random.randint(0,k-1);
    if (l>r):
        l,r = r,l
    print(l,r)

for _ in range(0,q):
    ned = ''.join(random.choice(dig) for _ in range(k))
    a = random.randint(0,m-1);
    b = random.randint(0,m-1);
    if (a>b) :
        a,b = b,a
    print(ned, a, b)


