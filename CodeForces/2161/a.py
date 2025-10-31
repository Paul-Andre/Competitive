t = int(input())
for _ in range(t):
    R0, X, D, n = map(int,input().split())
    R = R0
    s = input().strip()
    tot = 0;
    for c in s:
        if c == "1":
            tot += 1;
            R = max(0, R-D);
        else:
            if (R<X):
                tot += 1;
    print(tot);






