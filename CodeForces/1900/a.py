t = int(input())

for _ in range(t):
    n = int(input())
    s = input().strip()
    stretch = 0
    infinite = False
    tot = 0
    for c in s:
        if c == ".":
            stretch+=1
            tot+=1
            if stretch == 3:
                infinite = True
        else:
            stretch = 0
    if infinite:
        print(2)
    else:
        print(tot)
