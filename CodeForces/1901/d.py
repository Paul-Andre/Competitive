n = int(input())
A = list(map(int, input().split()))

n = len(A)

if (n == 1):
    print(A[0])
    exit()

B = [a+i for i,a in enumerate(A)]
C = [a+(n-1-i) for i,a in enumerate(A)]

B_acc = [0]*n
B_acc[-1] = B[-1]
for i in range(2,n+1):
    B_acc[-i] = max(B_acc[-i+1], B[-i])

C_acc = [0]*n
C_acc[0] = C[0]
for i in range(1,n):
    C_acc[i] = max(C_acc[i-1], C[i])

cands = []
for i in range(1,n-1):
    cand = max(C_acc[i-1], A[i], B_acc[i+1])
    cands.append(cand)

cands.append(max(A[0], B_acc[1]))
cands.append(max(C_acc[-2], A[-1]))

print(min(cands))
