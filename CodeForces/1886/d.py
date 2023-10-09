MOD = 998244353

n,m = map(int, input().split())
s = input()

def inverse(a):
    assert( a != 0);
    return pow(a, -1, MOD)


# prod = 1;

# # everything except the first element, which is 0, which we treat specially
# for i in range(1, len(toggles)):
#     if toggles[i]:
#         prod *= i
#         prod %= MOD

# def pront():
#     if toggles[0] == False:
#         print(prod)
#     else:
#         print(0)

# pront()


class Tree():
    def __init__(this, a, b, init):
        this.a = a
        this.b = b
        if (b>a):
            c = (a+b)//2
            this.left = Tree(a,c, init)
            this.right = Tree(c+1,b, init)
            this.prod = this.left.prod * this.right.prod % MOD
        else:
            this.left = this.right = None
            assert(a==b)
            this.prod = init[a]

    def set(this, k, v): 
        if (k < this.a or k > this.b): return;
        if (this.a == this.b):
            this.prod = v;
            return;

        this.left.set(k,v)
        this.right.set(k,v)
        this.prod = this.left.prod * this.right.prod % MOD

toggles = [c == "?" for c in s]
nums = [(i if b else 1) for i,b in enumerate(toggles)]
# print(nums)

tree = Tree(0, len(nums) - 1, nums);

def pront():
    print(tree.prod)

pront()

for _ in range(m):
    i,c = input().split()
    i = int(i)
    i-=1
    is_on = c=="?"

    if toggles[i] == is_on:
        pass;

    elif toggles[i] == False and is_on == True:
        toggles[i] = True

        tree.set(i, i);
        # if (i != 0):
        #     prod *= i
        #     prod %= MOD
    else:
        toggles[i] = False

        tree.set(i, 1);
        # if (i != 0):
        #     prod *= inverse(i)
        #     prod %= MOD;

    pront()



