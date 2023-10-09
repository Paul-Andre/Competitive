t = int(input())

def dist(U,V):
    ux,uy = U
    vx,vy = V
    return ((ux-vx)**2 + (uy-vy)**2)**.5

for _ in range(t):
    P = tuple(map(int, input().split()))
    A = tuple(map(int, input().split()))
    B = tuple(map(int, input().split()))
    O = (0,0);

    OA = dist(O,A);
    OB = dist(O,B);
    AP = dist(A,P);
    BP = dist(B,P);
    AB = BA = dist(A,B);

    def check(w):
        return (
                (OA <= w and AP <= w) or
                (OB <= w and BP <= w) or
                (OA <= w and AB<=2*w and BP <= w) or
                (OB <= w and BA<=2*w and AP <= w)
                )

    l = 0.
    r = 10000.
    for _ in range(100):
        m = (l+r)/2
        if (check(m)):
            r = m;
        else:
            l = m

    print(l);


