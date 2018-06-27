l1 = input()
l2 = input()
string = input()

mp = {}
for a,b in zip(l1, l2):
    mp[a] = b;



def trans(c):
    if c.isalpha():
        r = mp[c.lower()]
        if c.isupper():
            return r.upper()
        else:
            return r
    else:
        return c

print ( "".join(map(trans, string)))
        
