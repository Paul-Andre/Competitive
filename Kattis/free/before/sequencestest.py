import itertools
def replace(a):
    return {"0":[0],"1":[1],"?":[0,1]}[a]

def inv(a):
    return 1-a

def count(a):
    return sum([n*sum(map(inv,a[i+1:])) for i,n in enumerate(a)])

s = input()

combinations = map(list, itertools.product(*(map(replace,s))))
tot = 0;
for co in combinations:
    coun = count(co)
    tot=(tot+coun)%1000000007
    #//print (co, coun)

print(tot)

