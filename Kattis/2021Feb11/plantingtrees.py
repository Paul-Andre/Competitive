input()
a = list(map(int, input().split()))
a = [-aa for aa in a]
a.sort()
print(max( i+2+ (-a) for (i,a) in enumerate( a)))
