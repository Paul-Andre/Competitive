#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'superDigit' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING n
#  2. INTEGER k
#

def sumDigit(n:int):
    s = 0
    while(n):
        q = n//10
        r = n%10
        s+=r
        n=q
    return s
        
def superDigit(n, k):
    s = sumDigit(n)*k
    if (s > 9):
        return superDigit(s, 1)
    return s
    
    
    

if __name__ == '__main__':

    while(True):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        k = int(first_multiple_input[1])

        result = superDigit(n, k)
        print(result)
