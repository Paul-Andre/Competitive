from math import gcd,lcm
t = int(input())
for _ in range(t):
    n, = map(int, input().split())
    P = list(map(int, input().split()))
    S = list(map(int, input().split()))
    assert(len(P) == n)
    assert(len(S) == n)

    if (n==1):
        print("YES" if P[0] == S[0] else "NO")
        continue

    good = True
    good = good and S[0] == gcd(P[0], S[1])
    good = good and P[-1] == gcd(P[-2], S[-1])


    for i in range(1, n-1):
        A,B = P[i-1],P[i]
        D,C = S[i],S[i+1]
        good = good and A%B==0
        good = good and C%D==0
        AC = gcd(A,C)
        good = good and gcd(AC,B) == gcd(AC,D)
        if not good:
            break;

        #x0 = lcm(B,D)

        #good = good and gcd(x0, 

    print("YES" if good else "NO")

        







