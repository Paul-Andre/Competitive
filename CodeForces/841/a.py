n,k = map(int,input().split())
s = input()

ar = [0]*26
for b in s:
    ar[ord(b)-ord('a')]+=1


m = max(ar)

if (m <= k):
    print("YES")
else:
    print("NO")


