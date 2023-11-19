t = int(input())
for _ in range(t):
    n = int(input())
    A = list(map(int, input().split()))

    ret = 0;

    for i in range(1, n+1):
        if n%i == 0:
            b = [0 for _ in range(n//i)]
            for j,a in enumerate(A):
                jj = j//i
                b[jj]+=a
            diff = max(b) - min(b)
            ret = max(ret, diff)
    print(ret)
        

                



