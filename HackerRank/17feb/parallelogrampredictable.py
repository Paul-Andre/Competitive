import random
import sys
if len(sys.argv)>=2 :
    num = int(sys.argv[1])
else:
    num = 800
print(num,num)
for i in range(0,num) :
    for j in range(0,num) :
        sys.stdout.write("W");
    print();
print(3)
print(1,1,1,1)
print(1,2,3,4)
print(1,1,num,num)




