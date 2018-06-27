input();
a = list(map(int, input().split()))
m = max(a);

n =len(a)

if(m<=25):
    print(0);
else:
    print(m-25)



