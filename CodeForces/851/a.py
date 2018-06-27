n,k,t = map(int, input().split())

first = max(1, min(n, t))
last = max(1, min(n, t-k+1))

print(first -last + 1)
