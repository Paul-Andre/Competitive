t = int(input())
for _ in range(t):
    n = int(input())
    if n<=6 or n==9:
        print("NO")
    else:
        print("YES")
        r = n%3;
        if (r != 0):
            print("1 2", n-3)
        else:
            print("1 4", n-5)

