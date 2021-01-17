input()
a = list(map(int, input().split()))
a.sort()

if a[-3]+a[-2] <= a[-1]:
    print("NO");
else:
    b = a[0:-2] + [a[-1]] + [a[-2]]
    print("YES");
    print(" ".join(map(str, b)))
    

