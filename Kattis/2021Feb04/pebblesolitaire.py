n = int(input())
sol = {}
def get(s):
    if (s in sol):
        return sol[s]
    ss = s
    s = list(s)
    m = s.count('o')
    for i in range(0,23-2):
        if (s[i]=='o' and
                s[i+1]=='o' and
                s[i+2]=='-' ):
            ns = list(s)
            ns[i]='-'
            ns[i+1]='-'
            ns[i+2]='o'
            m = min(m,get("".join(ns)))
        if (s[i]=='-' and
                s[i+1]=='o' and
                s[i+2]=='o' ):
            ns = list(s)
            ns[i]='o'
            ns[i+1]='-'
            ns[i+2]='-'
            m = min(m,get("".join(ns)))
    sol[ss] = m
    return m

for _ in range(n):
    s = input()
    print(get(s))

