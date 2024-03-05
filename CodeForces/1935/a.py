t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    r = "".join(reversed(s))
    assert(n>=2)
    n = n%2
    if (n == 0):
        print(min(s, r+s))
    else:
        print(min(r, s+r))






