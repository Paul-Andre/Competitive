
n = 78124

res = [1];
for i in range(1,n+1):
    su = 0;
    for j in range(1,20):
        su += i//(5**j)

    r = res[i-1]
    if (su%2==0):
        r+=1;
    res.append(r)

for j in range(1,8):
    print((5**j)-1,res[(5**j)-1])
