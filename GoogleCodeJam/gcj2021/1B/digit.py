t,n,b,p =map(int,input().split())
for _ in range(t):
    stack = [0]*n
    for _ in range(n*b):
        d = int(input())
        if(d == 9):
            v,i = max( (v,i) for (i,v) in enumerate(stack) if (v<b))
            print((i+1))
            stack[i]+=1
        elif(d >= 8):
            seq = [(v,i) for (i,v) in enumerate(stack) if (v<b-1)]
            if(seq):
                v,i = max(seq)
                print((i+1))
                stack[i]+=1
            else:
                v,i = max( (v,i) for (i,v) in enumerate(stack) if (v<b))
                print((i+1))
                stack[i]+=1
        else:
            seq2 = [(v,i) for (i,v) in enumerate(stack) if (v<b-2)]
            seq1 = [(v,i) for (i,v) in enumerate(stack) if (v<b-1)]
            seq0 = [(v,i) for (i,v) in enumerate(stack) if (v<b)]
            if(seq2):
                v,i = max(seq2)
                print((i+1))
                stack[i]+=1
            elif(seq1):
                v,i = max(seq1)
                print((i+1))
                stack[i]+=1
            else:
                v,i = max(seq0)
                print((i+1))
                stack[i]+=1
input()


