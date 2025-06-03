t = int(input())
for _ in range(t):
    n,q = [int(a) for a in input().split()]
    s = input().strip()
    cb = 0
    cbba = 0
    ba = 0

    bc = 0
    bcca = 0
    ca = 0

    for _ in range(q):
        x,y = input().split()
        if x == "a": continue

        if (x,y) == ("c","b"):
            cb+=1

        if (x,y) == ("b","a"):
            if cb:
                cb-=1
                cbba+=1
            else:
                ba+=1

        if (x,y) == ("b","c"):
            bc+=1

        if (x,y) == ("c","a"):
            if bc:
                bc-=1
                bcca+=1
            else:
                ca+=1

    newS = []
    for z in s:
        if z=="a":
            newS.append("a");
        if z=="b":
            if ba:
                ba-=1
                newS.append("a");
            elif cbba:
                cbba-=1
                cb+=1
                ba+=1

                ba-=1
                newS.append("a");
            elif bcca:
                bcca-=1
                newS.append("a");
            else:
                newS.append("b")
        if z=="c":
            if ca:
                ca-=1
                newS.append("a")
            elif bcca:
                bcca-=1
                bc+=1
                ca+=1

                ca-=1
                newS.append("a")
            elif cbba:
                cbba-=1
                newS.append("a")
            elif cb:
                cb-=1
                newS.append("b")
            else:
                newS.append("c")
    print("".join(newS));






