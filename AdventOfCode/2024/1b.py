import sys
import math
from collections import Counter
s = 0
A = []
B = []
for line in sys.stdin:
    a,b = map(int, line.strip().split())
    A.append(a)
    B.append(b)

A.sort();
B.sort();

Bc = Counter(B);

for a in A:
    s += a*Bc[a]

print(s);
