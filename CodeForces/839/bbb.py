n,k = map(int, input().split())
A = list(map(int, input().split()))

middles = n
sides = n*2
singles = 0

#A.sort(reverse=True)

for i,a in enumerate(A):
    m = a//4
    s = min(m, middles)
    middles -= s
    a -= s*4

    m = a//2
    s = min(m, sides)
    sides -= s
    a -= s*2

    if (a == 3 and singles >= 3):
        singles -= 3
        a = 0

    if (a == 2 and singles >= 2):
        singles -= 2
        a = 0

    if (a == 1 and singles >= 1):
        singles -= 1
        a = 0

    if (a == 3 and middles != 0):
        middles -= 0
        a = 0

    if (a == 2 and middles != 0):
        middles -= 1
        a = 0
        singles += 1

    if (a == 1 and middles != 0):
        middles -= 1
        a = 0
        sides += 1

    if (a == 1 and sides != 0):
        sides -= 1
        a = 0

    while(a > 0 and singles > 0):
        a-=1
        singles-=1

    if a != 0:
        print("NO")
        exit()

        



print("YES")
