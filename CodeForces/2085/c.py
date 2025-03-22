t = int(input())
for _ in range(t):
    x,y = map(int,input().split());

    if(x==y):
        print(-1);
    elif (x>y):
        print((1<<40)-x)
    else:
        print((1<<40)-y)

