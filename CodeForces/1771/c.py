sieve = [True for _ in range(4*10**4)]
primes = []
i = 2
while( i<len(sieve)):
    if sieve[i]:
        primes.append(i)
        j = i*2
        while (j<len(sieve)):
            sieve[j] = False
            j+=i
    i+=1

#print(primes)

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(a) for a in input().strip().split()]
    has = set()
    succ = False

    for a in A:
        div_by = False
        for p in primes:
            if a%p == 0:
                a//=p
                while(a%p==0):
                    a//=p
                if p in has:
                    succ = True
                has.add(p)
        if a!=1:
            if a in has:
                succ = True
            has.add(a)


    if succ:
        print("YES")
    else:
        print("NO")



