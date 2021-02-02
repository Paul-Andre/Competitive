import heapq

while(True):
    n, b = map(int, input().split())
    if n==-1:
        break;
    a = [int(input()) for _ in range(n)]
    input()

    ta = sum(a)
    portion = -(-ta/b)


    if (n==1):
        print(-(-a[0]//b))
    else:
        h = [(-aa, 1, aa) for aa in a]
        heapq.heapify(h)

        rem_ballots = b-n;
        while(rem_ballots):
            _,have,people = heapq.heappop(h)
            rem_ballots-=1
            have+=1
            while(-people//have < h[0][0] and rem_ballots):
                rem_ballots-=1
                have+=1
            heapq.heappush(h, (-people//(have), have, people))

        print(-h[0][0])





