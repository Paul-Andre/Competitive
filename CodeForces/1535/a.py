n=int(input())
for _ in range(n):
    a,b,c,d= map(int, input().split())
    s = sorted([a,b,c,d])
    ab = max(a,b);
    cd = max(c,d);
    if (sorted([ab,cd]) == s[2:]) :
        print("YES")
    else:
        print("NO")

