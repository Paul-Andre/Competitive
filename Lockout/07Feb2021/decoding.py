input()
s = list(input())
n=len(s)
t = ['.']*n
if n%2==0:
    for i in enumerate(n):
        if (i<n//2):
            t[i] == s[n-2-2*i]
        else:
            t[i] == s[2*(



