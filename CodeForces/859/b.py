import math
n =int(input())

def sqq(n):
    m = math.floor(math.sqrt(n))
    for i in range(max(0,m-10), m+20):
        if i*i > n:
            return i-1


m = sqq(n)
    
if (n == m*m):
    print(4*m)
elif n<= m*(m+1):
    print(2*(m+m+1))
else:
    print(4*(m+1))

