import sys
X = int(sys.stdin.readline())
N = int(sys.stdin.readline())
print( sum( X - a for a in map(int, sys.stdin)) + X)
