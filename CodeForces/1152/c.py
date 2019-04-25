a,b = map(int, input().split())

if (a > b) :
    tmp = a
    a = b
    b = tmp

g = b - a

r = a % g

if (r == 0):
    print(0)
    exit(0)
else:
    print(r - 


