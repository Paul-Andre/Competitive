import random
t=1
for _ in range(t):
    m,n=100,100
    print(m,n)
    for _ in range(m):
        print("".join(random.choice("-") for _ in range(n)))


