th,tw,n = map(int, input().split())
x = map(int, input().split())


h = 0
w = 0
for xi in x:
    w += xi
    if (w == tw):
        w = 0
        h+=1
        if (h== th):
            print("YES")
            exit()
    elif (w>tw):
        print("NO")
        exit()

print("NO")
