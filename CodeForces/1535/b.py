import math
t=int(input())
for _ in range(t):
    n=int(input())
    A = list(map(int,input().split()))
    evenX = 0
    oddX = 0
    nEven = 0
    nOdd = 0
    for a in(A):
        if (a%2==0) :
            nEven+=1;
        else:
            nOdd+=1;

    for i,a in enumerate(A):
        for j,b in enumerate(A):
            if i>=j:
                continue
            if a%2==0 and b%2==0:
                if math.gcd(a,b) > 1:
                    evenX+=1

            if a%2==1 and b%2==1:
                if math.gcd(a,b) > 1:
                    oddX+=1
    #print(evenX, oddX, nEven, nOdd)
    tot = evenX + oddX + nEven*nOdd
    print(tot)

