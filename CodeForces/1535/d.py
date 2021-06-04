k=int(input())

n = 2**k
s=list(input())
s = [-1] + list(reversed([{'0': 0, '1': 1, '?': 2}[c] for c in s]))


counts = [0]*(len(s)) + [1]*len(s)

def recalc(p) :
    c = s[p]
    if (c == 2):
        counts[p] = counts[p*2] + counts[p*2+1]
    else:
        counts[p] = counts[p*2+ 1-c]

def recalc_up(p) :
    if (p==0): return
    recalc(p);
    recalc_up(p//2)

for i in reversed(range(1, n)):
    recalc(i)

#print(s)
#print(counts)
q=int(input())
for _ in range(q):
    p,c=input().split()
    p=int(p)
    p = n-p
    s[p]={'0':0, '1': 1, '?': 2}[c]
    recalc_up(p)
    print(counts[1])




