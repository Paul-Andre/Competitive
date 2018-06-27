m = 1000
mm = m+1
res = [True] *mm
res[0] = False
res[1] = False
ret = []
for i in range(2, mm):
    if res[i]:
        ret.append(i)
        for j in range(0, mm, i):
            res[j] = False

print(len(ret))
