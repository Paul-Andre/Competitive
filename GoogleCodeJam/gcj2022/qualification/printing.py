n = int(input())
for nnn in range(n):
    print ("Case #{}: ".format(nnn+1), end="")
    A = [list(map(int, input().split())) for _ in range(3)]
    B = [min(a[j] for a in A) for j in range(4)]
    if sum(B) < 10**6:
        print("IMPOSSIBLE")
        continue
    C = [0 for _ in range(4)]
    for i,b in enumerate(B):
        sc = sum(C)
        need = 10**6-sc
        provide = min(b, need)
        C[i] = provide
    print(" ".join(repr(c) for c in C))





