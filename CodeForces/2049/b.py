t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    good = False
    ret = "NO"
    if all(c == "s" or c=="." for c in s):
        ret = "YES"
    if all(c == "p" or c=="." for c in s):
        ret = "YES"
    if all(c == "s" or c=="." for c in s[:-1]) and s[-1] == "p":
        ret = "YES"
    if all(c == "p" or c=="." for c in s[1:]) and s[0] == "s":
        ret = "YES"
    print(ret)


        



