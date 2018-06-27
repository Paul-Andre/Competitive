n = int( input());
a = list(map(int, input().split()))

i = 1
const = 0

while i<n:
    if a[i-1]<a[i] :
        i+=1
    else:
        break;

while i<n:
    if a[i-1]==a[i] :
        i+=1
        const=1
    else:
        break

while i<n:
    if a[i-1]>a[i] :
        i+=1
    else:
        break

if i==n:
    print("YES")
else :
    print("NO")






