n = int(input())

letters = [chr(i) for i in range(ord('a'), ord('z')+1)]
for _ in range(n):
    s = set(input())
    missing = ""
    for l in letters:
        if l in s or l.upper() in s:
            pass
        else:
            missing+=l
    if missing:
        print("missing {}".format(missing))
    else:
        print("pangram")


