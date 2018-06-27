N = int(input())
arms = []
for _ in range(N):
    arms.append(int(input()))

target = tuple(map(int, input().split()))

x = target[0]
y = target[1]

distance = (x**2 +y**2) **(1/2);

decoArms = [(-arm, i) for i,arm in enumerate(arms)]
decoArms.sort()

arms = [-arm for (arm, i) in decoArms]

lower = [arms[0]]
upper = [arms[0]]

for arm in arms[1:] :
    upper.append(upper[-1] + arm)
    lower.append(lower[-1] - arm)

#print(upper, lower)

if ( distance != 0):
    if (distance > upper[-1]):
        x *= upper[-1] /distance
        y *= upper[-1] /distance
    elif (distance < lower[-1]):
        x *= lower[-1] /distance
        y *= lower[-1] /distance
else:
    x = max(0, lower[-1])
    y = 0



def dist(x, y):
    return (x**2 +y**2) **(1/2);

res = []

def show(x, y, arms, lower, upper):
    if (len(arms)==1):
        res.append((x,y))
        return

    d2 = dist(x,y)
    #print("x,y", x,y)
    #print("d2", d2)
    if ( d2 <= upper[-2] and d2 >= lower[-2] ) :
        d1 = d2
    elif d2 <= upper[-2] :
        d1 = lower[-2]
    else :
        d1 = upper[-2]

    if (d2 == 0) :
        show(0, arms[-1], arms[:-1], lower[:-1], upper[:-1])
        #print(x, y)
        res.append((x,y))
        return

    a = arms[-1]
    #print(d1, d2, a)

    nx = x/d2
    ny = y/d2
    # create new coordinate for next arm
    ax = (a*a - d1*d1 - d2*d2)/-2/d2
    ay = (max(0,d1*d1 - ax*ax))**(1/2)
    #print("d1**2", d2)
    # rotate those coordinates
    nay = nx*ax - ny*ay
    nax = ny*ax + nx*ay

    show(nay, nax, arms[:-1], lower[:-1], upper[:-1])
    res.append((x,y))

show(x, y, arms, lower, upper)

prev = (0,0)
dists = []
for (i,r) in enumerate(res):
    dists.append( ( decoArms[i][1] , (r[0]-prev[0], r[1] - prev[1])))
    prev = r

dists.sort()

x = 0
y = 0

for (_, (dx, dy)) in dists :
    x += dx
    y += dy
    print("%.5f %.5f" % (x,y))
