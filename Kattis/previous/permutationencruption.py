while(True):
    a = list(map(int, input().split()))
    if a[0]==0:
        break;
    n = a[0]
    perm = a[1:]
    s = list(input())
    t = []
    for i in range(-((- len(s))//n)):
        for j in range(n):
            ind = i*n+perm[j]
            if (ind > len(s)):
                t.append(" ")
            else:
                t.append(s[ind-1])
    print("'{}'".format("".join(t)))



