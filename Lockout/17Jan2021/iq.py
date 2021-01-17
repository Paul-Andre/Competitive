n =int(input())
a = list(map(int, input().split()))

b = [i%2 for i in a]
if b[0] != b[1] and b[0]!=b[2]:
    print(1)
else:
    for i,a in enumerate(b):
        if a != b[0]:
            print(i+1)
            break
