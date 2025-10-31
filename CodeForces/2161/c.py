t = int(input())
for _ in range(t):
    n,X = map(int,input().split())
    A = list(map(int,input().split()))
    A.sort();
    S = sum(A);
    taken = S//X;
    acc = 0;
    supposed_ans = sum(A[-taken:]);

    i =0;
    j = len(A)-1;
    ans = 0
    ret = []
    while(i<=j):
        current = acc//X
        if (acc+A[j])//X > current:
            acc += A[j];
            ans += A[j];
            ret.append(A[j]);
            j-=1
        else:
            acc += A[i];
            ret.append(A[i]);
            i+=1

    print(ans);
    print(" ".join(map(str, ret)));




    





    




