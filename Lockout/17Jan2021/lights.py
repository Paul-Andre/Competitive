a = [
0b110100000,
0b111010000,
0b011001000,

0b100110100,
0b010111010,
0b001011001,

0b000100110,
0b000010111,
0b000001011,
]

b = (list(map(int, input().split())) + 
 list(map(int, input().split())) +
 list(map(int, input().split())))

s = 0b111111111;
for i,bb in enumerate(b):
    if (bb%2==1):
        s = s^a[i]

def asdf(n):
    return str(int(bool( s & (1<<n))))

print(asdf(8)+asdf(7)+asdf(6))
print(asdf(5)+asdf(4)+asdf(3))
print(asdf(2)+asdf(1)+asdf(0))

