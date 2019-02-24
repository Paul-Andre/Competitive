import sys

k = [0,1,2,5,9,8,6]

for aa in sys.stdin:
    a = int(aa)
    l = []

    if a == 0:
        print("0")
        continue

    while a != 0:
        d = a//7
        r = a%7
        l.append(r)
        a = d

    print("".join(str(k[v]) for v in l))


