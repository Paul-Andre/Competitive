while(True):
    x=int(input())
    if(x==0):
        break;
    neg = False
    if (x < 0):
        neg=True
        x = -x

    done = False
    for y in range(1, int(x**.5)+100):
        n = 1
        for z in range(1, 32+1):
            n*=y
            if n==x:
                if not neg or (z%2):
                    print(z)
                    done=True
                    break;
            elif n>x:
                break;
        if done:
            break;
    if not done:
        print(1)


