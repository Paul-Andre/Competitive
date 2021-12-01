import sys
prev = None
cnt=0
for l in sys.stdin:
    l = l.strip()
    if (l == ""): continue
    l = int(l.strip())
    if (prev is not None) and (l>prev):
        cnt+=1;
    prev = l
print(cnt)

