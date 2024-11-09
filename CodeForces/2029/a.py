t = int(input())
for _ in range(t):
    l,r,k = map(int, input().split())
    rr = r//k;
    print(max(0,rr-l+1));
