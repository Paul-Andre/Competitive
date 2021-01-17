n = int(input())
vis = [False]*n

vis[0] = True
k = 0
for i in range(n):
    k+=(i+1)
    k=k%n
    vis[k] = True

if(all(vis)):
    print("YES")
else:
    print("NO")
