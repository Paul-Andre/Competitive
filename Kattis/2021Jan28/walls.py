import functools
l,w,n,r = map(int,input().split())
points = [tuple(map(int,input().split())) for _ in range(n)]
def create(x,y):
    ret = 0
    if (x-l/2)**2 + y**2 <= r**2:
        ret|=1
    if (x+l/2)**2 + y**2 <= r**2:
        ret|=2
    if x**2 + (y-w/2)**2 <= r**2:
        ret|=4
    if x**2 + (y+w/2)**2 <= r**2:
        ret|=8
    return ret

good = [create(x,y) for (x,y) in points]
#print(good)
if max(good) == 15:
    print(1)
elif max(a|b for a in good for b in good) == 15:
    print(2)
elif max(a|b|c for a in good for b in good for c in good) == 15:
    print(3)
elif (functools.reduce(lambda a,b: a|b, good) == 15):
    print(4)
else:
    print("Impossible")


