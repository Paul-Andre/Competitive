import sys
a = []
for l in sys.stdin:
    l = l.strip()
    if (l == ""): continue
    l = int(l.strip())
    a.append(l)

b = [a[i]+a[i+1]+a[i+2] for i in range(0, len(a)-2)]

tot=0
for i in range(0, len(b)-1):
    if b[i+1] > b[i]:
        tot+=1
print(tot)


