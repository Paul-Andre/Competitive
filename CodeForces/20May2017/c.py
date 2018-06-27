n = int(input())
x = list(map(int, input().split() ))

MOD = 10**9 + 7

x.sort()

diff = []
for i in range(1,n):
    diff.append(x[i] - x[i-1])

tot = 0;
totSide = 0;
po = 1;
poSum = 0;

for d in diff:
    poSum+= po;
    poSum %= MOD
    totSide *= 2
    totSide += d*poSum;
    totSide %= MOD
    tot += totSide;
    tot %= MOD
    po*= 2;
    po %= MOD

print(tot)

