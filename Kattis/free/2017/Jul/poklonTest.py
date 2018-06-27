import random

N = 100000
print(N)

for _ in range(N):
    A = random.randint(1, 10**6)
    B = random.randint(1, 10**6)
    if ( A == 1 and B == 1) :
        print(1,2);
    elif ( A == 10**6 and B == 10**6) :
        print(10**6 - 1, 10**6);
    elif ( A == B):
        print(A , A+1);
    else:
        if B < A:
            tmp = B
            B = A
            A = tmp

        print( A, B)

