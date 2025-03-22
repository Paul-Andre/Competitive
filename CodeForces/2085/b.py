from collections import Counter
def mex(A):
    assert(all(a>=0 for a in A))
    B = sorted(set(A));
    i = 0
    j = 0
    while j<len(B):
        b = B[j];
        if b>i:
            return i;
        elif b==i:
            i+=1
            j+=1
        else:
            j+=1
    return i



t = int(input())
for _ in range(t):
    n = int(input())
    A = list(map(int, input().split()));
    n = len(A);
    #print("<<<<",A)

    A1 = A[0:2]
    A2 = A[2:]
    z1 = 0 in A1
    z2 = 0 in A2
    def run(l,r):
        assert(l<=len(A));
        assert(r<=len(A));
        assert(l<r);
        print(l,r)
        A[(l-1):(r)] = [mex(A[(l-1):(r)])]
        #print(">>>>",A)

    if z1 and z2:
        print(3)
        run(1,2)
        run(2,n-1)
        run(1,2)
        assert(A==[0])
    elif z1 and not z2:
        print(2)
        run(1,2)
        run(1,n-1)
        assert(A==[0])
    elif not z1 and z2:
        print(2)
        run(2,n)
        run(1,2)
        assert(A==[0])
    else: # not z1 and not z2
        assert(not z1 and not z2)
        print(1)
        run(1,n)
        assert(A==[0]);


        





