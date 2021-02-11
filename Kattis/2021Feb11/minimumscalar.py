t = int(input())
for tt in range(t):
    input()
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    a = [-aa for aa in a]
    a.sort()
    b.sort()
    print("Case #"+str(tt+1)+": "+str(-sum(aa*bb for aa,bb in zip(a,b))))
