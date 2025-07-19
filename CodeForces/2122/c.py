import random
for _ in range(int(input())):
    n, = map(int, input().split())
    A = [tuple(map(int,input().split())) for _ in range(n)]

    # arbitrary tie breaking
    A = [(x+random.random()*0.1, y+random.random()*0.1) for x,y in A]
    #print(A)

    X = [x for x,y in A]
    Y = [y for x,y in A]
    #print(X)

    X.sort();
    Y.sort();

    tot = 0
    #tot += sum(abs(a-b) for a,b in zip(X,reversed(X)))/2
    #tot += sum(abs(a-b) for a,b in zip(Y,reversed(Y)))/2
    #print(tot)


    core_x_l = X[n//2-1]
    #core_x_r = X[n//2]
    core_y_l = Y[n//2-1]
    #core_y_r = Y[n//2]

    ll = [];
    lr = [];
    rl = [];
    rr = [];
    for i,(x,y) in enumerate(A):
        check = (x<= core_x_l),(y<=core_y_l)
        #print(check)
        if check == (0,0):
            ll.append((i,x,y))
        elif check == (0,1):
            lr.append((i, x,y))
        elif check == (1,0):
            rl.append((i, x,y))
        elif check == (1,1):
            rr.append((i, x,y))
        else:
            assert(False)
    assert(len(ll) == len(rr));
    assert(len(rl) == len(lr));

    other_tot = 0
    for ((i, a,b),(j,c,d)) in zip(ll,rr):
        print(i+1, j+1)
        other_tot += abs(a-c) + abs(b-d)
    for ((i, a,b),(j,c,d)) in zip(lr,rl):
        print(i+1, j+1)
        other_tot += abs(a-c) + abs(b-d)

    #print(other_tot)





    


