t=int(input())
for _ in range(t):
    r,b,d=map(int,input().split())
    if r>b:
        r,b=b,r
    g = b//r
    if(b%r!=0):
        g+=1
    g-=1
    if g>d:
        print("NO")
    else:
        print("YES")

