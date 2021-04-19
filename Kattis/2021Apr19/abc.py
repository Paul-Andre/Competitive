ABC=sorted(map(int, input().split()))
s = input()
ss = [ABC[ord(a)-ord('A')] for a in s]
print(" ".join(map(str, ss)))


