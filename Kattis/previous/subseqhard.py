for _ in range(int(input())):
    input()
    input()
    A = list(map(int,input().split()))
    m = {0:1}
    sum = 0
    tot = 0
    for a in A:
        sum+=a
        if sum not in m:
            m[sum]=0
        m[sum]+=1
        if sum-47 in m:
            tot+=m[sum-47]
    print(tot)





