import random
import sys
if len (sys.argv) >= 2 :
    n= int(sys.argv[1])
else:
    n = 5
print(n)

for i in range(2,n+1) :
    print(i, random.randint(1,i-1))
for i in range(0,n) :
    print(random.randint(0,1000), random.randint(0,1000))
