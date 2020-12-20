import sys

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


n,t = map(int, input().split())
s = input()

def pos(c):
    return ord(c) - ord('a')

want = [0]*30
have = [0]*30

t -= 2**pos(s[-1])
t += 2**pos(s[-2])

if t < 0:
    t *= -1

i=0
while(t):
    want[i] = t % 2
    t//=2
    i+=1

for c in s[:-2]:
    have[pos(c)]+=1

eprint(have)
eprint(want)

good =True
for i in range(29, -1, -1):
    h = want[i]
    if (h>n or h<-n) :
        good = False
        break;
    can_remove = min(h, have[i])
    have[i] -= can_remove
    if (have[i] % 2) :
        good = False
        break;
    h -= can_remove
    if (i==0):
        if (h!=0):
            good = False;
            break;
    else:
        want[i-1] += h*2

if good:
    print("Yes")
else:
    print("No")
