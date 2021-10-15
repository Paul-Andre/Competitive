while(True):
    try:
        line = input()
    except EOFError:
        break;
    a = [int(l) for l in line.split()][1:]
    n = len(a)
    c = set()
    for i in range(0, len(a)-1):
        c.add(abs(a[i+1]-a[i]))
    #print(c)
    jolly = True
    for i in range(1, n):
        if i not in c:
            jolly=False
    if jolly:
        print("Jolly")
    else:
        print("Not jolly")

