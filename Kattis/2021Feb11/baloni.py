from collections import Counter
n = int(input())
a =(map(int, input().split()))
tot = 0
flying = Counter()
for v in a:
    if flying[v] > 0:
        flying[v]-=1
        flying[v-1]+=1
    else:
        tot+=1
        flying[v-1]+=1
print(tot)



