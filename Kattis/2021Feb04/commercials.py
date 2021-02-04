n,p=map(int,input().split())
a = list(map(int,input().split()))
a = [aa-p for aa in a]
cumul = [0]
for aa in a:
    cumul.append(cumul[-1]+aa)
msf = 0
best = 0
for aa in cumul:
    best = max(best, aa-msf)
    msf = min(msf, aa)
print(best)



