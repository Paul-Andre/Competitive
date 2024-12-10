import sys
import math
tot_safe = 0
for line in sys.stdin:
    A = list(map(int, line.strip().split()))
    grad_inc = True;
    grad_dec = True;
    for i in range(len(A)-1):
        a,b = A[i], A[i+1]
        if not (3>=(b-a)>=1):
            grad_inc = False
        if not (3>=(a-b)>=1):
            grad_dec = False
    if grad_inc or grad_dec:
        #print("safe")
        tot_safe += 1
    else:
        pass;
        #print("unsafe")

print(tot_safe);
