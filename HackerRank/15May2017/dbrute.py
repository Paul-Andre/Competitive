n = int(input())
s = list(input())

tot = 0
for i in range(n):
    for j in range(n):
        for k in range(n):
            if (s[i]=="a" and s[j]=="b" and s[k]=="c" and (j+1)**2 == (i+1)*(k+1)) :
                tot += 1

print(tot)

