t = int(input())
for _ in range(t):
    a,b = map(int, input().split(":"))
    if a < 12:
        ap = "AM"
    else:
        ap = "PM"

    h = a%12
    if h == 0:
        h = 12

    print(f"{h:#02}:{b:#02} {ap}")


