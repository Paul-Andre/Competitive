n = int(input())
a = map(int, input().split())
i = 0
for aa in a:
    if aa < 0:
        i+=1
print(i)
