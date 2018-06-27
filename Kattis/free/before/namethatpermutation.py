import math;
import sys;
def printPer(n, nums):
    if (len(nums)==1):
        print(nums[0]);
    else:
        f = math.factorial(len(nums)-1);
        mod = n%f;
        div = n//f;
        sys.stdout.write(str(nums[div])+" ");
        nums[div:div+1]=[];
        printPer(mod,nums);

for line in sys.stdin:
    (n, k) = map(int, line.split())
    printPer(k,[i for i in range(1,n+1)])


