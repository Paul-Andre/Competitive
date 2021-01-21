case_counter=1
while True:
    try:
        m,n=map(int, input().split())
    except EOFError:
        break

    sky = [list(input()) for _ in range(m)]
    vis = [[False for _ in range(n)] for _ in range(m)]


    count = 0
    for i in range(0,m):
        for j in range(0,n):
            if not vis[i][j] and sky[i][j] == '-':
                #print(i,j)
                count+=1
                visitList = []
                visitList.append((i,j))
                vis[i][j]=True
                while(len(visitList) != 0):
                    x,y = visitList.pop()
                    for dx,dy in [(0,1), (0,-1), (1, 0), (-1, 0)]:
                        xx =  x+dx
                        yy =  y+dy
                        if xx>=0 and xx<m and yy>=0 and yy<n :
                            if not vis[xx][yy] and sky[xx][yy]=='-':
                                vis[xx][yy] = True
                                visitList.append((xx,yy))

    print("Case {}: {}".format(case_counter, count))
    case_counter+=1


