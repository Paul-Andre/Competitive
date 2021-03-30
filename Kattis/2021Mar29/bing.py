from collections import Counter
n = int(input())
c = Counter()
for _ in range(n):
    s = input()
    print(c[s])
    for i in range(1,len(s)+1):
        c[s[:i]]+=1
    #print(c)



