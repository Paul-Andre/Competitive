import random

n = 16
print(n)

l = []
for i in range(1,n):

    r = random.randint(1,i);

    l.append(str(r))

print(" ".join(l))


ll = []
for i in range(1, (n//2) + 1):
    ll.append(str(i));
    ll.append(str(i));

random.shuffle(ll)
print(" ".join(ll))







