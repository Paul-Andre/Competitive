N, B, H, W = map(int, input().split())

def f(n):
    return n>=N;

m = None

for i in range(H):
    price = int(input())
    av = map(int, input().split())
    for avv in av:
        if (avv>=N) :
            if (m!= None) :
                m = min(price,  m);
            else:
                m = price
           

if (m==None):
    print("stay home")
elif (m*N <= B):
    print (m*N)
else :
    print("stay home")
    

