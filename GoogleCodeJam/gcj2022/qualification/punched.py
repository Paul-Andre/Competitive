n = int(input())
for nnn in range(n):
    print ("Case #{}:".format(nnn+1))
    x,y = map(int,input().split())
    print("..+" + "-+"*(y-1))
    print("..|" + ".|"*(y-1))
    print("+" + "-+"*(y))
    for _ in range(x-1):
        print("|" + ".|"*(y))
        print("+" + "-+"*(y))

