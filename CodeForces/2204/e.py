from collections import Counter
t = int(input())
for _ in range(t):
    inp = input()
    s = [int(c) for c in inp]
    tot = sum(s);

    if (len(s) == 1):
        print(inp)
        continue


    all_digits_cnt = Counter(s);


    for j in range(tot, max(tot-100,0),-1):

        i = j
        rem_digits_cnt = all_digits_cnt.copy()
        succ = False
        while True:
            i_digits = [int(c) for c in str(i)]
            i_digits_cnt = Counter(i_digits);
            if not (i_digits_cnt <= rem_digits_cnt):
                break;
            rem_digits_cnt -= i_digits_cnt

            if (i<=9):
                succ = True;
                break;

            i = sum(i_digits);

        

        if (succ):
            if sum(k*v for k,v in rem_digits_cnt.items()) == j:
                for (k,v) in reversed(sorted(rem_digits_cnt.items())):
                    print(str(k)*v, end="");

                i = j
                while True:
                    print(i,end="")
                    i_digits = [int(c) for c in str(i)]

                    if (i<=9):
                        break;

                    i = sum(i_digits);
                print()
                break



