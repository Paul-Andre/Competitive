N,T =map(int,input().split())
A,B,C,t0 = map(int,input().split())
tt = [t0]
for _ in range(1,N):
    tt.append((A*tt[-1] + B) % C +1)

#print(tt)
tt.sort()
np = 0
penalty = 0
tottime = 0
for p in tt:
    if tottime+p>T:
        break
    tottime+=p
    penalty+=tottime
    np+=1
print(np, penalty%1000000007)



