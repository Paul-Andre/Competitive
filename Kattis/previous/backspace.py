s = input()
l = []
for c in s:
    if c == '<':
        l.pop()
    else:
        l.append(c)
print("".join(l))

