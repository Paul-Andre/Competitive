import heapq
n,m=map(int,input().split())
a = list(map(int, input().split()))

q = list(a)
heapq.heapify(q)
tot = 0
peopel = n
while peopel:
    v = heapq.heappop(q)
    tot += v
    peopel-=1
    if (v > 1):
        heapq.heappush(q,v-1)

pp = tot

q = [-aa for aa in a]
heapq.heapify(q)
tot = 0
peopel = n
while peopel:
    v = -heapq.heappop(q)
    tot += v
    peopel-=1
    if (v > 1):
        heapq.heappush(q,-(v-1))

print(tot, pp)

