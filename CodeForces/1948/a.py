t = int(input())
T = "AABB"*25
for _ in range(t):
    n = int(input())
    if n%2 == 0:
        print("YES")
        print(T[:n])
    else:
        print("NO")


