def win(n,m):
    if n>m:
        n,m=m,n
    if (m%n == 0): return True
    if (m>n*2): return True
    a = m%n
    return not win(a,n);


while(True):
    n,m = map(int,input().split())
    if(n==0 and m==0):
        break;
    if win(n,m):
        print("Stan wins")
    else:
        print("Ollie wins")


