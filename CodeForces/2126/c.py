t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    H = list(map(int, input().split()))
    current = H[k-1]
    H = sorted(set(h for h in H if h> current))

    level = 1
    good = True
    for h in H:
        diff = h-current
        time_left = current+1-level
        if diff > time_left:
            good = False
            break;
        current = h
        level += diff

    print("YES" if good else "NO")





