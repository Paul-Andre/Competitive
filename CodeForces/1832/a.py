from collections import Counter
a = int(input())
for _ in range(a):
    b = Counter(input())
    poss = True
    if len(b) == 1:
        poss = False
    elif len(b) == 2:
        for k,v in b.items():
            if v == 1:
                poss = False;
    if poss == False:
        print("NO")
    else:
        print("YES")



