import itertools
import sys

def col(i):
    pass;
    #sys.stdout.write('\x1b[6;30;42m' + str(i) + '\x1b[0m')
    
def nocol(i):
    pass
    #sys.stdout.write(str(i))

n = 5

dic = [0]*(n+1)
for s in itertools.permutations(range(0,n)):
    count = 0
    if s[0]<s[1]:
        col(s[0]);
        count +=1
    else:
        nocol(s[0]);

    for i in range(1, len(s)-1):
        if s[i-1]>s[i] or s[i+1]>s[i]:
            col(s[i]);
            count +=1
        else:
            nocol(s[i]);
    
    if s[-1]<s[-2]:
        col(s[-1]);
        count +=1
    else:
        nocol(s[-1]);

    
    dic[count] += 1;

    #print("  " + str(count))


ss = sum(dic)
su = 0
for i, d in enumerate(dic):
    print(i, d, ss- su)
    su += d




