from collections import Counter
t = int(input())
for _ in range(t):
    n = int(input())
    A = list(map(int, input().split()));
    if (len(Counter(A)) != len(A)):
        print(-1)
    else:
        print(" ".join(map(str,reversed(sorted(A)))))

