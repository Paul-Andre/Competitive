n =  int(input())
seen = set()

for _ in range(n):
    x = input()
    if x in seen:
        print("YES")
    else:
        print("NO")
        seen.add(x)


