from collections import defaultdict

t = int(input())

for _ in range(t):
    n = int(input())
    a,b = map(int, input().split())
    tree = defaultdict(list)

    for _ in range(n-1):
        x,y = map(int, input().split())
        x-=1
        y-=1
        tree[x].append(y);
        tree[y].append(x);

    stack = []
    stack.append(a);


    vis = [False for _ in range(n)]
    stack.append(
    while(stack):
        x = stack.pop();
        vis[x] = True
        for y in tree[x]:
            if not vis[y]:
                stack.append(y);




