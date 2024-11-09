from collections import Counter
t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    r = input()
    cs = Counter(s);

    s0 = cs["0"]
    s1 = cs["1"]
    good = True
    for c in r:
        if not s0 or not s1:
            good = False;
        if c=="0":
            s1-=1
        else:
            s0-=1
    if good:
        print("YES");
    else:
        print("NO");



    
    



