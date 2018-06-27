n = int(input());
a = list(map(int,input().split()))

a.sort();

d0 = 0
for i in range(0,n//2):
    d0 += abs(a[i] - (i*2+2)); 
d1 = 0
for i in range(0,n//2):
    d1 += abs(a[i] - (i*2+1)); 
print(min(d0, d1));
    

