a,b,c,n = map(int,input().split())

aa = a - c
bb = b - c
if (aa < 0 or bb < 0):
    print(-1)
    exit(0)
feast = aa + bb + c
stay = n - feast
if (stay < 1):
    print(-1)
    exit(0)

print(stay)

