n = int(input())

have = [0]
for i in range(1,n+1):
    new_have = []
    for n in have:
        for d in range(0,10):
            if n*10+d != 0 and (n*10+d)%i==0:
                new_have.append(n*10+d)
    print(i, len(have))
    have=new_have

print(len(have))

