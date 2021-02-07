x =(input())
y =(input())
n = len(x)

fail = False
for (a,b) in zip(x,y):
    if (a<b):
        fail = True

if fail:
    print(-1)
else:
    print(y)


