n = int(input())
a = list(map(int,input().split()))

count = 0
good =False
for i,j in enumerate(a):
    if i==j:
        count+=1
    elif a[j]==i:
        good=True


if count ==n:
    print(n)
elif good:
    print(min(n, count+2))
else:
    print(count+1)


