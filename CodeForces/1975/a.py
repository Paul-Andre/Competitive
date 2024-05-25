t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    good = 0
    for i in range(len(a)-1):
        if a[i+1] >= a[i]:
            good+=1

    good += (a[0] >= a[-1])

    if (good >= n-1):
        print("Yes");
    else:
        print("No");



