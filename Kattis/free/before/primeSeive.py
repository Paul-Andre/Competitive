import math

n = math.ceil(math.sqrt(2000001))
seive = [True]*n
seive[0] = seive[1] = False;

primes = [];
num = 0;
for i in range(2,n):
    if seive[i]:
        num+=1;
        primes.append(i)
        print(i);
        for j in range(i,n,i):
            seive[j]=False

print(num);
print(primes)
