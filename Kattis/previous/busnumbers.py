input()
a = list(map(int, input().split()))
a.sort()

first = a[0]
last = a[0]
for b in a[1:]:
    if b==last+1:
        last=b
    else:
        if last-first == 0:
            print(last,end=" ")
        elif last-first == 1:
            print(first,last,end=" ")
        else:
            print("{}-{}".format(first,last),end=" ")
        first = b
        last = b

if last-first == 0:
    print(last)
elif last-first == 1:
    print(first,last)
else:
    print("{}-{}".format(first,last))

