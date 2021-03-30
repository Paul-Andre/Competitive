t = int(input())
for _ in range(t):
    n = int(input())
    nums = []
    for _ in range(n):
        s = input()
        nums.append((len(s), s))
    nums.sort()
    seen = set()
    good= True
    for _,num in reversed(nums):
        if num in seen:
            good= False
            break;
        for i in range(1, len(num)+1):
            seen.add(num[0:i])
    if(good):
        print("YES")
    else:
        print("NO")



