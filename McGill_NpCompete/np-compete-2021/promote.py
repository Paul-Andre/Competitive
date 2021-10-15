n,k = map(int, input().split())
names = list(input().split())
values = list(map(int,input().split()))
for i in range(0, n):
    if (values[i] > k):
        print(names[i])


