def f(n):
    if (n==0):
        return 0
    if (n<=2):
        return 1
    return 1 + f((n-2)/3)

print([(i, f(i)) for i in range(51)])
print(sum([(f(i)) for i in range(51)]))
