import math

def simplify(x,y):
    g = math.gcd(x,y)
    return (x//g, y//g)

def gt(a,b):
    (ax,ay) =a 
    (bx,by) =b
    return ay*bx > ax*by

def mult(a,b):
    (ax,ay) =a 
    (bx,by) =b
    return simplify(ax*bx, ay*by)

c = None
vis = None
matrix = None

def visit(a, source, best_rat):
    if (a == source and vis[a] and gt(best_rat, (1,1))):
        return True;
    if(vis[a]) :
        return False
    vis[a] = True
    for j in range(c):
        new = mult(best_rat, matrix[a][j]);
        if gt(matrix[source][j], new):
            new = matrix[source][j];
        if (not vis[j]):
            if visit(j, source, new) :
                return True
    return False


def matrixSqr(m):
    ret = [[(1,0) for _ in  range(c)] for _ in range(c)]
    for i in range(c):
        for j in range(c):
            best = (1,0)
            for k in range(c):
                n = mult(m[i][k], m[k][j])
                if gt(n, best):
                    best = n
            ret[i][j] = best
    return ret;


while(True) :
    c = int(input())
    if (c == 0): break;
    currencies = input().split()
    cur_to_ind = { s: i for  (i,s) in enumerate(currencies)}
    ind_to_cur = { i: s for  (i,s) in enumerate(currencies)}
    n = int(input())
    matrix = [[(1,0) for _ in  range(c)] for _ in range(c)]
    for i in range(n):
        for i in range(c):
            matrix[i][i] = (1,1)
        a,b,r = input().split()
        r = tuple(map(int,r.split(":")))
        a = cur_to_ind[a];
        b = cur_to_ind[b];
        matrix[a][b] = r

    arb = False
    for _ in range(10):
        matrix = matrixSqr(matrix)
        for i in range(c):
            if gt(matrix[i][i], (1,1)):
                arb = True
        if arb:
            break;
    if (arb) :
        print("Arbitrage")
    else:
        print("Ok")











