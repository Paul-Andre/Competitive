n = int(input())

a = list(map(int, input().split()))

a = [ i*2 for i in a]

tot = sum(a)

target = 9*n


a.sort()
cnt = 0
if (tot >= target):
    print(0)
    exit(0)

for v in a:
    tot += (10 - v)
    cnt +=1 
    if (tot >= target):
        print(cnt)
        exit(0)
    


