def gcd(a,b):
    if b > a:
        tmp = a
        a = b
        b = tmp
    while True:
        if (b == 0):
            return a
        c = a%b
        a = b
        b = c

def sqrt(x):
    a = 1
    b = x
    while a < b:
        c = (a+b)//2
        cc = c*c
        if cc == x:
            return c
        elif cc < x:
            a = c + 1
        else:
            b = c
    return a
    

def getSome(a,b):
    if (a != b):
        return gcd(a,b)
    return None


T = int(input())
for ttt in range(1,T+1):
    N, L = map(int, input().split())
    A = list(map(int, input().split()))
    L = len(A)
    inter = [None]
    for i in range(0, L-1):
        inter.append(getSome(A[i], A[i+1]))
    inter.append(None)

    for i in range(0, L):
        if inter[i+1] is None and inter[i] is not None:
            inter[i+1] = A[i] // inter[i]
    
    for i in reversed(range(0, L)):
        if inter[i+1] is not None and inter[i] is None:
            inter[i] = A[i] // inter[i+1]

    dump = list(set(inter))
    dump.sort()
    mm = { a : chr(ord('A') + i) for i,a in enumerate(dump) }
    result = "".join(map(mm.get, inter))
    print("Case #" + str(ttt) + ": " + result)

