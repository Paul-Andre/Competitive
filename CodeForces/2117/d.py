import sys
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

t = int(input())
for _ in range(t):
    n, = map(int, input().split())
    A = list(map(int, input().split()))
    n = len(A)
    a = A[0]
    b = A[-1]

    good = True

    y_num = (b-n*a)
    y_denom = (1-n*n)

    assert(y_denom != 0)
    if (y_num%y_denom != 0):
        good = False
        print("NO")
        continue

    y = y_num//y_denom
    x = a - n*y

    #eprint("x,y",x,y)

    assert(a == x + n*y)
    assert(b == y + n*x)

    if (x< 0 or y < 0):
        good = False
        print("NO")
        continue

    for i,e in enumerate(A):
        if e != (i+1)*x + (n-(i+1)+1)*y:
            good = False
    if good:
        print("YES")
    else:
        print("NO");
      


    
