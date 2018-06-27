import random
import sys
if len(sys.argv)>=2 :
    num = int(sys.argv[1])
else:
    num = 800
print(num,num)
for i in range(0,num) :
    for j in range(0,num) :
        sys.stdout.write(random.choice(["B","W"]))
    print();

if len(sys.argv)>=3 :
    numQ = int(sys.argv[2])
else:
    numQ = 1000
print(numQ)
for i in range(0,numQ) :
    x1 = random.randint(1,num)
    y1 = random.randint(1,num)
    x2 = random.randint(1,num)
    y2 = random.randint(1,num)
    if x1 > x2:
        x1, x2 = x2, x1
    if y1 > y2:
        y1, y2 = y2, y1
    print(x1,y1,x2,y2)
    

