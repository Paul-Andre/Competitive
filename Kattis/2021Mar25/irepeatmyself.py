n = int(input())
for _ in range(n):
    s = list(input())
    for m in range(1,len(s)+1):
        good = True
        for i in range(0, len(s)):
            if s[i] != s[i%m]:
                good = False
                break;
        if good:
            print(m)
            break


