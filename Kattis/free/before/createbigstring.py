import random
import string
print("abc"*510510);
print("a"*1048576);
print("abc"*312793);
print(''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(2000000)))
print(''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(1999999)))
print((''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(1099999//1687)))*1687)
print((''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(1999999//510510)))*510510)
print((''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(1999999//(2**15))))*2**15*3)
print(".");
