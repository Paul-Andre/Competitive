from collections import Counter

def get_most_common_count(c):
    return c.most_common(1)[0][1]

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    n = len(s)

    printed = False
    for i in range(1,n+1):
        if (n%i == 0):
            q = n//i
            num_one_off = 0;
            good = True
            for j in range(i):
                d = Counter();
                for k in range(q):
                    ix = j+k*i
                    # print(ix);
                    d[s[ix]]+=1;

                if get_most_common_count(d) == q:
                    pass
                elif get_most_common_count(d) == q-1:
                    num_one_off +=1
                else:
                    good = False;

            if num_one_off<=1 and good:
                print(i)
                printed = True
                break;

    assert(printed)






