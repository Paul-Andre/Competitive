t = int(input())
for _ in range(t):
    n = int(input())
    A = list(map(int,input().split()))
    ret = 2;
    i = 0
    while(i<len(A) and A[i]==0):
        i+=1
    while(i<len(A) and A[i]!=0):
        i+=1
    while(i<len(A) and A[i]==0):
        i+=1

    if i==len(A):
        ret = 1

    if all(a==0 for a in A):
        ret = 0

    print(ret)

        





