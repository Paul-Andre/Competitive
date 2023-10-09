t = int(input())
output = []
for _ in range(t):
    s = input()
    n = len(s);

    pos = int(input())

    # Get the index of the string we're looking for
    i_s = 1

    cur_p = pos
    cur_n = n;

    while(cur_p > cur_n):
        #print(cur_p, cur_n);
        cur_p -= cur_n;
        cur_n -= 1;
        i_s += 1
        assert(cur_n >= 1)
        assert(cur_p >= 1)

    to_rem = i_s-1;
    removed = 0;

    s = s+"!"
    new_s = []

    for c in s:
        # squash
        while new_s and new_s[-1] > c and removed < to_rem:
            new_s.pop();
            removed += 1
        new_s.append(c)

    #print(cur_p)
    #print(new_s);

    output.append(new_s[cur_p-1]);

print("".join(output))










