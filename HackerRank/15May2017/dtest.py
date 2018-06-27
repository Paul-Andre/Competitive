from random import *;
import sys;
n = 100;
if len(sys.argv) >=2 :
    n = int(sys.argv[1])

print(n)
print("".join([choice(["a","b","c"]) for _ in range(n)]))
