import sys
a = [list(input()) for _ in range(5)]

b = (
    [
        [
            "***",
            "* *",
            "* *",
            "* *",
            "***",
        ],[
            "  *",
            "  *",
            "  *",
            "  *",
            "  *",
        ],[
            "***",
            "  *",
            "***",
            "*  ",
            "***",
        ],[
            "***",
            "  *",
            "***",
            "  *",
            "***",
        ],[
            "* *",
            "* *",
            "***",
            "  *",
            "  *",
        ],[
            "***",
            "*  ",
            "***",
            "  *",
            "***",
        ],[
            "***",
            "*  ",
            "***",
            "* *",
            "***",
        ],[
            "***",
            "  *",
            "  *",
            "  *",
            "  *",
        ],[
            "***",
            "* *",
            "***",
            "* *",
            "***",
        ],[
            "***",
            "* *",
            "***",
            "  *",
            "***",
        ]
    ])

l = (len(a[0])+1)//4

s = ""
allgood = True
for i in range(l):
    allgood = False
    for n in range(10):
        good = True
        for x in range(3):
            for y in range(5):
                if a[y][i*4 + x] == b[n][y][x]:
                    pass
                else:
                    good=False
        if good:
            s+=str(n)
            allgood =  True
            break
    if not allgood:
        break

if allgood:
    allgood = int(s,10)%6==0


print(s,file=sys.stderr)
if allgood:
    print("BEER!!")
else:
    print("BOOM!!")




