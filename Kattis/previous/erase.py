n = int(input())
a = input()
b = input()
if (n%2==0):
    succ = (a == b)
else:
    succ = True
    for aa,bb in zip(a,b):
        if (aa == '0' and bb=='1') or (aa=='1' and bb=='0'):
            pass
        else:
            succ = False

if succ:
    print("Deletion succeeded")
else:
    print("Deletion failed")
    

