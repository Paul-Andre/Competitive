n = int(input())
for _ in range(n):
    h, w = map(int, input().split())
    for _ in range(h-1):
        print("B"*w)
    print("W" + "B"*(w-1))
        

