import itertools
n = int(input())
strings = list(map(str, input().split()))
n = len(strings)

suits = 'shdc'
ranks = '23456789TJQKA'
maxrank = len(ranks)-1

cards = [(suits.find(s[1]), ranks.find(s[0])) for s in strings]

#print(strings)
#print(cards)
#input()

minn = 100000000;
for ordering in itertools.permutations([0,1,2,3]):
    #print("Ordering",ordering);
    for ascending in itertools.product([1, -1], repeat = 4):
        #print ("==============")
        copy = [(ordering[s], ascending[s]*r) for (s,r) in cards]
        #print (copy)
        #print (ordering, ascending)

        t = [0 for i in range(0,n)]
        t[0] = 1

        for i in range(1,len(copy)):
            maxx = 1
            for j in range(0,i):
                mm = t[j]
                if copy[i]>copy[j]:
                    mm+=1
                    maxx = max (mm, maxx)
            t[i] = maxx

        #print(t)
        #print(n-max(t));
        minn = min(minn, n-max(t));

print(minn);

