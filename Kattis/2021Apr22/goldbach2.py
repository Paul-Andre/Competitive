sieve = [True]*32321;
sieve[0] = False
sieve[1] = False
for i in range(2, len(sieve)):
    if sieve[i]:
        for j in range(i*2, len(sieve), i):
            sieve[j] = False

#print(sieve[0:20])

t=int(input())
for _ in range(t):
    x = int(input())
    re = []
    for i,f in enumerate(sieve):
        if f and sieve[x-i]:
            re.append((i, x-i))
        if i*2 >= x:
            break;
    print("{} has {} representation(s)".format(x, len(re)))
    for a,b in re:
        print("{}+{}".format(a,b))
    print()

