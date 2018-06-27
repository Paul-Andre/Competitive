n = int(input())

tot = sum(map(int, input().split()))

m = int(input())

P = []
for i in range(m):
    l,r = map(int, input().split())
    P.append((l,r))

for l,r in P:
    if (l<=tot and tot<=r) :
        print(tot)
        exit(0)
    elif (tot<=l) :
        print(l)
        exit(0)

print(-1)
