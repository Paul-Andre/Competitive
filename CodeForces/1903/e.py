from sys import stdout
t = int(input())
from collections import Counter
for _ in range(t):
    n = int(input())
    # print("n", n);
    sx,sy = map(int, input().split())
    sp = (sx+sy)%2
    A = []
    for _ in range(n):
        x,y = map(int, input().split())
        p = (x+y)%2
        pp = (sp+p)%2
        # print(x,y,p,pp)
        A.append(pp)

    cnt = Counter(A)
    # print(cnt)
    if cnt[0] >= cnt[1]:
        print("First")
        my_turn = True
    else:
        print("Second")
        my_turn = False
    stdout.flush();

    picked = [False]*n

    index = 0

    did = 0

    phase = int(my_turn)
    while(index < n):
        if did >= n:
            break;
        if my_turn:
            while(index < n and (picked[index] or A[index]!=phase)):
                index += 1
            if (index >= n):
                break;
                
            picked[index] = True

            print(index+1)
            stdout.flush();
            did+=1
        else:
            opposed = int(input())-1
            if opposed == -2:
                exit(0)
            picked[opposed] = True
            did+=1
        my_turn = not my_turn

    index = 0
    phase = 1-phase
    while(index < n):
        if did >= n:
            break;
        if my_turn:
            while(index < n and picked[index]):
                index += 1
            if (index >= n):
                break;
            picked[index] = True

            print(index+1)
            stdout.flush();
            did+=1
        else:
            opposed = int(input())-1
            if opposed == -2:
                exit(0)
            picked[opposed] = True
            did+=1
        my_turn = not my_turn

    




