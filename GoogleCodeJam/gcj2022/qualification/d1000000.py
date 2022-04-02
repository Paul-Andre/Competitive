kkk = int(input())
for kkkk in range(kkk):
    print ("Case #{}: ".format(kkkk+1), end="")
    n = int(input())
    A = list(map(int, input().split()))
    A.sort()
    accum = 0
    for a in A:
        if a>=accum+1:
            accum+=1
    print(accum)





