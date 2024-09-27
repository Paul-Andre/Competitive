t = int(input())
for _ in range(t):
    n = int(input())
    A = list(map(int, input().split()))
    Ae = [a for (i,a) in enumerate(A) if i%2==0]
    Ao = [a for (i,a) in enumerate(A) if i%2==1]

    if len(A)==1:
        print(A[0]+len(A));
        continue

    #print(Ae)
    #print(Ao)
    print(max(max(Ae)+len(Ae), max(Ao)+len(Ao)));


