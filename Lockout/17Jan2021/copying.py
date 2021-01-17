input()
a = list(map(int,input().split()))
n = len(a)
b = []
for aa in a:
    if aa == 1:
        aa =n
    elif aa == n:
        aa= 1
    b.append(aa)
print(" ".join(map(str,b)))
