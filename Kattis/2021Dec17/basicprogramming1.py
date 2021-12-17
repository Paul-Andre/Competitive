n,t = map(int, input().split())
A = list(map(int, input().split()))
if t==1:
    print(7)
elif t==2:
    if (A[0] > A[1]) : print("Bigger")
    elif (A[0] == A[1]) : print("Equal")
    else : print("Smaller")
elif t==3:
    a = A[0:3]
    a.sort()
    print(a[1])
elif t==4:
    print(sum(A))
elif t==5:
    print(sum(a for a in A if (a%2==0)))
elif t==6:
    print("".join( chr(ord("a") + (a%26)) for a in A))
elif t==7:
    seen = [False for _ in range(n)]
    i = 0
    seen[i] = True
    while(True):
        i = A[i]
        if (i<0 or i>=n):
            print("Out")
            break;
        if (i==n-1):
            print("Done")
            break;
        if seen[i]:
            print("Cyclic")
            break;
        seen[i] = True


