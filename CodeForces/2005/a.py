t = int(input());
for _ in range(t):
    n = int(input());
    m = n//5;
    l = n%5;
    ret = ""
    for c in "aeiou":
        if l:
            ret+=c*(m+1);
            l-=1
        else:
            ret+=c*m;
    print(ret);



