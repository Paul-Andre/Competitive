from math import lcm

t = int(input())

def calc(a,b,c,m):
    return (
            6*(m//a)
            - 3*(m//lcm(a,b))
            - 3*(m//lcm(a,c))
            + (6 - 4)*(m//lcm(a,b,c))
            )

for _ in range(t):
    a,b,c,m = map(int,input().split())
    print(
            calc(a,b,c,m),
            calc(b,a,c,m),
            calc(c,a,b,m),
            )


