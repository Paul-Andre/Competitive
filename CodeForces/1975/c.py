t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    best = min(a[0], a[1])

    for i in range(len(a)-2):
        best = max(best, sorted(a[i:i+3] )[1])

    for i in range(len(a)-1):
        best = max(best, sorted(a[i:i+2])[0])

    print(best);

