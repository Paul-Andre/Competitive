D = int(input())
R = int(input())
T = int(input())

for i in range(4,1000) :
    r = i*(i+1)//2 - 6
    t = T+R-r
    for j in range(3,1000) :
        tt = j*(j+1)//2 - 3
        if tt == t and i-j == D :
            print(R-r)
            exit()

