from collections import Counter
import math

t = int(input())
for _ in range(t):
    a,b,c = map(int,input().strip().split())

    if (a*2 + b != a+b+c-1):
        print(-1);
        continue;

    if a:
        a_levels = math.floor(math.log2(a))+1
        a_rem = a - (2**(a_levels-1) -1)

        a_space = 2**(a_levels - 1) - a_rem

        # print(a_levels, a_rem, a_space);
        if (b <= a_space):
            print(a_levels)
            continue

        b_top = b-a_space

        b_space = a_rem*2 + a_space
    else:

        a_levels = 0
        b_top = b
        b_space = 1



    b_levels = b_top//b_space + (not (not(b_top%b_space)))

    print(a_levels+b_levels)




