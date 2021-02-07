from collections import Counter
n = int(input())
a = [int(input()) for _ in range(n)]
c = Counter(a)
if len(c) == 2 and list(c.items())[0][1]==n//2:
    print("YES")
    print(list(c.items())[0][0], list(c.items())[1][0])
else:
    print("NO")



