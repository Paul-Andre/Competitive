#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'legoBlocks' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER m
#

MOD = 10**9 + 7

def legoBlocks(n, m):
    # C_m = The number of ways to build a single (non-solid) row of m legos
    # C_0 = 1    C_{<0} = 0
    # A_m = The number of ways to build a (possibly non-solid) n*m wall
    # B_m = The number of ways to build a solid n*m wall
    # A_0 = B_0 = 1
    # Write your code here
    C = [0]*(m+1)
    A = [0]*(m+1)
    B = [0]*(m+1)
    C[0] = 1
    def get_C(i):
        if i<0:
            return 0
        return C[i]

    for i in range(1, m+1):
        C[i] =  (
        get_C(i-1)  +
        get_C(i-2)  +
        get_C(i-3)  +
        get_C(i-4)
        ) % MOD

    for i in range(0, m+1):
        A[i] = pow(C[i], n, MOD)

    for j in range(0, m+1):
        tot = A[j]
        for i in range(1, j-1+1):
            tot -= (B[i]*A[j-i])%MOD
            tot %= MOD
        B[j] = tot

    return B[m]





if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        m = int(first_multiple_input[1])

        result = legoBlocks(n, m)

        print(result)
        #fptr.write(str(result) + '\n')

    #fptr.close()
