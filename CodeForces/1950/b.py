t = int(input())
for _ in range(t):
    n = int(input())
    print(end="")
    for i in range(n):
        for _ in range(2):
            for j in range(n):
                for _ in range(2):
                    if (i+j)%2:
                        print(".", end="")
                    else:
                        print("#", end="")
            print()

