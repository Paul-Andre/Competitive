
def f(a):
    if a == '//':
        return '/'
    return a

sol = {}
for a in ["+","-","//","*"]:
    for b in ["+","-","//","*"]:
        for c in ["+","-","//","*"]:
            s = "4 %s 4 %s 4 %s 4" % (a,b,c)
            k = eval(s)
            ss = "4 %s 4 %s 4 %s 4" % tuple(map(f,(a,b,c)))
            sol[k] =  ss + " = " + str(k)

n = int(input())
for _ in range(n):
    m = int(input())
    print(sol.get(m, "no solution"))
    
