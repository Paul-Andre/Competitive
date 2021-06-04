
def ff(i,x):
    if (x=='?'): return '?'
    if i%2 == int(x): return '0'
    return '1'

t=int(input())
for _ in range(t):
    s = list(input())
    n = len(s)
    s = [ ff(i,x) for i,x, in enumerate(s)]

    tot = 0
    l=0
    r=0
    curr = s[0]
    if (curr == '?'):
        curr == '0'
    q = 0
    tot += 1
    r += 1
    while(l<n and r < n):
        #print(l,r, q, curr, tot)
        if s[r]=='?' and s[r-1] != '?':
            q = r
        if s[r] != '?' and s[r] != curr:
            curr = s[r]
            if s[r-1] == '?':
                l = q
            else:
                l = r
        tot +=  r-l+1
        r+=1
    #print(l,r, q, curr, tot)
    print(tot)
                





