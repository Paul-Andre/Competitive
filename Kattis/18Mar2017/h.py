L = input()
if (L=="0"):
    print(0)
    exit()

a = 0;
b = 10000000;

while(True):
    c = (a+b)//2
    v = len(str(c))*c
    if (v==L):
        logn = c
        exit()
    elif (v<L):
        a = c
    else:
        b=c

p
