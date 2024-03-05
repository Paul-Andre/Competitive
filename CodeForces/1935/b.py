from collections import Counter

def mex(A):
    cnt = Counter(A)
    for i in range(len(A)+1):
        if not cnt[i]:
            return i


def first_good(A, m):
    if (m==0):
        return 0
    B = [False]*m
    cnt = 0
    for i in range(len(A)):
        a = A[i];
        if a<m:
            if not B[a]:
                B[a] = True
                cnt+=1
                if cnt == m:
                    return i


t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(a) for a in input().strip().split()]
    assert(max(A) < n)
    m = mex(A)
    fg = first_good(A,m)
    fgr = n-1-first_good(list(reversed(A)), m)
    if not (fg<fgr):
        print(-1)
        continue

    print(2)
    print(1, fg+1)
    print(fg+2, n)

