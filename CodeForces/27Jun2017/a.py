c, v0, v1, a, l = map(int, input().split())

v = v0;

read = v;
day = 1;
v += a
v = min(v, v1)


if(read >= c):
    print(day)
    exit(0);


while(True):
    day +=1;
    read += v - l

    v+=a
    v = min(v, v1)
    if(read >= c):
        print(day)
        exit(0);

