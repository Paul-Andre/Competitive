words = set()
while(True):
    try:
        s = input()
    except EOFError:
        break
    ws = s.split()
    ww = []
    for w in ws:
        wl = w.lower()
        if wl in words:
            ww.append(".")
        else:
            ww.append(w)
            words.add(wl)
    print(" ".join(ww))


