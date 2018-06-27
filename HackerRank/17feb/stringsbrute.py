#!/bin/python3

import sys

def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count+=1
        else:
            return count

n,m,q,k = input().strip().split(' ')
n,m,q,k = [int(n),int(m),int(q),int(k)]
s = input().strip()
pairs = []
for pairs_i in range(m):
   pairs_t = [int(pairs_temp) for pairs_temp in input().strip().split(' ')]
   pairs.append(pairs_t)
for a0 in range(q):
    w,a,b = input().strip().split(' ')
    w,a,b = [str(w),int(a),int(b)]
    sum = 0
    for i in range(a,b+1):
        sum+=occurrences(s,w[pairs[i][0]:pairs[i][1]+1])
    print(sum )
    



