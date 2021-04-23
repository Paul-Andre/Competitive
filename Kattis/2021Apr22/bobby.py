import math

def binom(n,k):
    return math.factorial(n)//((math.factorial(n-k))*math.factorial(k))

n = int(input())
for _ in range(n):
    r,s,x,y,w = map(int, input().split())
    chance = 0
    for yy in range(x,y+1):
        chance += binom(y, yy)*((s-r+1)/s)**yy*((r-1)/s)**(y-yy)
    if chance*w > 1:
        print("yes")
    else:
        print("no")

