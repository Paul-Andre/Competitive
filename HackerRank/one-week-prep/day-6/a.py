# Enter your code here. Read input from STDIN. Print output to STDOUT

q = int(input())
s = []
undos = []
for _ in range(q):
    op = input().strip()
    if op[0] == "1":
        undos.append(list(s))
        w = op.split()[1]
        s.extend(w)
    elif op[0] == "2":
        undos.append(list(s))
        k = int(op.split()[1])
        del s[-k:]
    elif op[0] == "3":
        index = int(op.split()[1])
        print(s[index-1])
    elif op[0] == "4":
        s = undos.pop()
    print(s)
