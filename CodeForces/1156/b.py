from collections import Counter
T = int(input())

for _ in range(T):
    s = input()
    ss = sorted(s)
    c = Counter(s)
    cc = sorted(c.keys())
    sc = list(map(ord, sorted(c.keys())))
    def k(a):
        return cc[a] * c[cc[a]]

    if len(c) == 1:
        print(s)
    elif len(c) == 2:
        if sc[1] - sc[0] == 1:
            print ("No answer")
        else:
            print(s)
    elif len(c) == 3:
        if sc[1] - sc[0] == 1 and sc[2] - sc[1] == 1:
            print ("No answer")
        elif sc[1] - sc[0] == 1:
            print (cc[0]*c[cc[0]] + cc[2]*c[cc[2]] + cc[1]*c[cc[1]])
        else:
            print (cc[1]*c[cc[1]] + cc[0]*c[cc[0]] + cc[2]*c[cc[2]])
    else :
        acc = ""
        i = 1
        while(i < len(cc)):
            acc += k(i)
            i+=2
        i = 0
        while(i < len(cc)):
            acc += k(i)
            i+=2
        print(acc)

            

