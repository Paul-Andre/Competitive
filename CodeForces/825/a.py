input()
s = input()

print("".join(map(str, map(len, s.split("0")))))
