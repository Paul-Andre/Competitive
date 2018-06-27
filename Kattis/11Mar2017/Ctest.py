import sys

stack = [];
reg = {"A": 100000000, "X": 1000000000, "Y": 10000000000}

for line in sys.stdin:
    line  = line.strip()
    if (line == "AD"):
        a = stack.pop();
        b = stack.pop();
        stack.append(a+b)
    else:
        
        [c, r ]= line.split()
        if c=='PH':
            stack.append(reg[r])
        if c=='PL':
            reg[r] = stack.pop()
        if c=='ZE':
            reg[r] = 0;
        if c=='ST':
            reg[r] = 1;
        if c=='DI':
            print("And the answer is",reg[r])
            exit()




