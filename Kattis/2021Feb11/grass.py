while(True):
    try:
        n,l,w=map(int,input().split())
    except EOFError:
        break;

    xr = [tuple(map(int, input().split())) for _ in range(n)]


    lr = []
    for x,r in xr:
        pr = (r**2 - (w/2)**2)
        if pr <= 0: continue;
        pr = pr**.5
        lr.append((x-pr, x+pr))

    lr.sort()
    have = 0
    pos = 0
    tot = 0
    bad = False
    while(have < l):
        m = have
        if (pos >= len(lr) or lr[pos][0] > have):
            break;
        while(pos < len(lr) and lr[pos][0]<=have):
            m= max(m, lr[pos][1])
            pos+=1
        tot+=1
        have = m

    if (have < l):
        print(-1)
    else:
        print(tot)
