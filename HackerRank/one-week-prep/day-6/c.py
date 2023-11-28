#!/bin/python3

import math
import os
import random
import re
import sys
import heapq

#
# Complete the 'cookies' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY A
#

def cookies(k, A):
    A = list(A)
    heapq.heapify(A)
    count = 0
    while A[0] < k:
        if len(A) < 2:
            return -1;

        x = heapq.heappop(A)
        y = heapq.heappop(A)
        z = x+y*2
        heapq.heappush(A, z)
        count+=1

    return count
        




if __name__ == '__main__':

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    A = list(map(int, input().rstrip().split()))

    result = cookies(k, A)
    print(result); 
