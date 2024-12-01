import sys
import math
s = 0
A = []
B = []
for line in sys.stdin:
    a,b = map(int, line.strip().split())
    A.append(a)
    B.append(b)

A.sort();
B.sort();

for a,b in zip(A,B):
    s+= abs(a-b);

print(s);
