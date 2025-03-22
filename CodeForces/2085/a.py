from collections import Counter
t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    s = input()
    t = "".join(reversed(s));
    if k==0:
        if s<t:
            print("YES");
        else:
            print("NO");
    else:
        if len(Counter(s))>1:
            print("YES");
        else:
            print("NO");

