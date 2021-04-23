i = 1
while(True):
    try:
        asdf = input().split()
    except EOFError:
        break;

    x = float(asdf[0])
    y = float(asdf[1])
    r = int(asdf[2])

    zx, zy = 0,0
    good = "IN"
    for _ in range(r):
        zx,zy = (zx**2 - zy**2),  (2*zx*zy)
        zx+=x
        zy+=y
        d = (zx**2 + zy**2)**.5
        #print(zx, zy, d)
        if d > 2:
            good = "OUT"
            break;
    print("Case {}: {}".format(i, good))
    i+=1

