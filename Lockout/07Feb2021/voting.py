from collections import Counter
n=int(input())
aa = list(map(int,input().split()))
c = Counter()
best = 0
lead = 1
for a in aa:
    c[a]+=1
    if c[a]>best:
        best = c[a]
        lead = a

print(lead)



