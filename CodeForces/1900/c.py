#include <bits:
t = int(input())
import math

for _ in range(t):
    n = int(input())
    s = list(" "+input().strip());

    left = [0]*(n+1)
    right = [0]*(n+1)
    for i in range(1, n+1):
        l,r = map(int,input().split())
        left[i] = l
        right[i] = r

    best = [math.inf]*(n+1)

    def recurse(i):
        if i==0:
            return;

        l = left[i]
        r = right[i]

        if (l ==0 and r==0):
            best[i] = 0
            return

        recurse(r)
        recurse(l)


        c = s[i]
        l_add = c!="L"
        r_add = c!="R"
        best[i] = min(best[l]+l_add, best[r]+r_add)

    recurse(1)
    #print(best)
    print(best[1])



