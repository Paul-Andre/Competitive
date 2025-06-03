fib = [1,1,2]
for _ in range(3,20):
    fib.append(fib[-1]+fib[-2]);
#print(fib)

t = int(input())
for _ in range(t):
    n,m = map(int, input().split())
    ret = []
    for _ in range(m):
        dim = list(map(int,input().split()))
        dim.sort();
        good = (
                dim[0] >= fib[n] and
                dim[1] >= fib[n] and
                dim[2] >= fib[n+1]
                )
        ret.append(int(good))
    print("".join(map(str,ret)))

