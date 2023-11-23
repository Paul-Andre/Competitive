
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumBribes' function below.
#
# The function accepts INTEGER_ARRAY q as parameter.
#

def minimumBribes(q):
    tot = 0
    for i_ in range(len(q)):
        i = i_+1
        e = q[i_];
        # if element e is in position lower than where it belongs
        if i < e:
            if e-i > 2:
                print("Too chaotic")
                return
            tot+=e-i
    print(tot)
            


if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
