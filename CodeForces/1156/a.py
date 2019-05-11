n = int(input())
A = list(map(int, input().split()))

tot = 0
top = False
inf = False

for i in range(len(A) - 1):
    if (A[i] == 2 and A[i+1] == 3) or (A[i] == 3 and A[i+1] == 2) :
        inf = True;
        break
    if (A[i], A[i+1]) == (1,2):
        tot += 3
        if top:
            tot -= 1
        top = False
    if (A[i], A[i+1]) == (2,1):
        tot += 3
        top = False
    if (A[i], A[i+1]) == (1,3):
        tot += 4
        top = False
    if (A[i], A[i+1]) == (3,1):
        tot += 4
        top = True

if inf:
    print("Infinite")
else :
    print("Finite")
    print(tot)

        



