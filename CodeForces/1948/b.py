t = int(input())
T = "AABB"*25

def get_digits(a):
    return [int(b) for b in str(a)]

def is_sorted(L):
    for i in range(len(L)-1):
        if not (L[i] <= L[i+1]):
            return False
    return True

for _ in range(t):
    n = int(input())
    A = list(map(int, input().split()))
    n = len(A)

    # Considering all elements up till A[i] and their possibilities,
    # can we have A[i] broken (X[i]), or not broken (Y[i])
    X = [False]*n
    Y = [False]*n

    a = A[0];
    X[0] = True;
    Y[0] = is_sorted(get_digits(a))
    prev_digits = get_digits(a);
    for i in range(1, n):
        prev = A[i-1]
        a = A[i]
        digits = get_digits(a)

        if X[i-1]:
            if prev <= a:
                X[i] = True
            # I don't need to explicitly do the X -> Y transition,
            # because any if X->Y is true, so is Y -> Y
        if Y[i-1]:
            if is_sorted(prev_digits + [a]):
                X[i] = True
            if is_sorted(prev_digits + digits):
                Y[i] = True

        prev_digits = digits

    if X[n-1] or Y[n-1]:
        print("YES");
    else:
        print("NO")



