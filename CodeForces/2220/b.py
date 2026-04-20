from collections import Counter
t = int(input())
for _ in range(t):
    n,m = map(int,input().split())
    A = list(map(int, input().split()));
    current = -1;
    count = 1;
    bad = False
    for a in A:
        if a == current:
            count+=1;
        else:
            current = a;
            count=1;

        if count>= m:
            bad = True;
    if bad:
        print("NO");
    else:
        print("YES");



