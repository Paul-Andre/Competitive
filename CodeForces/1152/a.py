n,m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
n = len(A)
m = len(B)

AA = [0,0];
BB = [0,0];

for i in A:
    AA[i%2] +=1 
for i in B:
    BB[i%2] +=1 


print( min(AA[0], BB[1]) + min(AA[1], BB[0]))
