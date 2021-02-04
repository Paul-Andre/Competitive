n =int(input())
C = list(map(int,input().split()))
m =int(input())
S = list(map(int,input().split()))

MAXIMUM = 60000
prev = ["Impossible"]*MAXIMUM
prev[0]=-1
for ci,c in enumerate(C):
    for i in range(MAXIMUM):
        if (i-c >= 0) and prev[i-c] != "Impossible":
            if prev[i-c] == "Ambiguous":
                prev[i] = "Ambiguous"
            elif prev[i-c]!="Impossible":
                if prev[i] == "Impossible":
                    prev[i] = ci
                else:
                    prev[i] = "Ambiguous"

#print(list(enumerate(prev[:20])))
for s in S:
    if type(prev[s]) is str:
        print(prev[s])
    else:
        ss = s
        out = []
        while(ss!=0):
            out.append(prev[ss]+1)
            ss = ss-C[prev[ss]]
        out.sort()
        print(" ".join(map(str,out)))







