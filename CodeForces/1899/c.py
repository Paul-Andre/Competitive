t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(s) for s in input().split()]
    B = [A[0]]
    for a in A[1:]:
        if (a%2 == B[-1]%2):
            B[-1] = max(B[-1], a)
        else:
            B.append(a)

    C = []
    i = 0
    while True:
        a = B[i]
        if a<=0:
            neg_start = i
            i+=1
            while(i<len(B) and B[i]<=0):
                i+=1
            neg_end = i-1
            neg_len = neg_end - neg_start + 1
            if neg_len%2 == 0:
                pass
            else:
                best = max( B[j] for j in range(neg_start, neg_end+1, 2));
                C.append(best)
        else:
            C.append(a)
            i+=1


            


# Not finished


