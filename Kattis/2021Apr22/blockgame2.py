def win(n,m):
    if n>m:
        n,m=m,n
    if (m%n == 0): return True
    if (m>n*2): return True
    a = m%n
    return not win(a,n);


n,m = map(int,input().split())
if win(n,m):
    print("win")
else:
    print("lose")


