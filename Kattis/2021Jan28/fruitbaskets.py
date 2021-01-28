input()
A = list(map(int,input().split()))
tot = sum(A)*2**(len(A)-1)

for a in A:
    p = a
    if p<200:
        tot-=p

for i,a in enumerate(A):
    for j,b in enumerate(A):
        if (i<j): 
            p = a+b
            if p<200:
                tot-=p
for i,a in enumerate(A):
    for j,b in enumerate(A):
        for k,c in enumerate(A):
            if (i<j and j<k):
                p = a+b+c
                if p<200:
                    tot-=p

print(tot)
