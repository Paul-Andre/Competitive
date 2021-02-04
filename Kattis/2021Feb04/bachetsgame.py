while(True):
    try:
        i = input().split()
    except EOFError:
        break;

    n = int(i[0])
    m = int(i[1])
    a = list(map(int, i[2:]))

    w = [False]*(n+max(a) +5)
    i = 0
    while i < n+1:
        if not w[i]:
            for j in a:
                w[i+j]=True
            i+=1
        i+=1

    if w[n]:
        print("Stan wins")
    else:
        print("Ollie wins")






