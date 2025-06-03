import math
t = int(input())
for _ in range(t):
    x = int(input())
    a = math.floor(math.log2(x))
    print(a*2+3)
