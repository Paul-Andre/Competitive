import sys
import string


for line in sys.stdin:
    line = line.lower()
    a,b = line.split(",")

    ac = [0]*26
    bc = [0]*26

    for c in a:
        if ( c>= 'a' and c<='z'):
            ac[ord(c) - ord('a')]+=1
            
    for c in b:
        if ( c>= 'a' and c<='z'):
            bc[ord(c) - ord('a')]+=1

    good = True
    for i in range(26):
        if (ac[i] != bc[i]) :
            print("Invalid Pattern")
            good = False
            break
        
    if good:
        print("Valid Pattern")




