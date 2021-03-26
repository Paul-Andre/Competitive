a = [int(a) for a in  input().split(":")]
b = [int(b) for b in  input().split(":")]
a = a[0]*60*60 + a[1]*60 + a[2]
b = b[0]*60*60 + b[1]*60 + b[2]
d = (b-a)%(24*60*60)
if (d == 0):
    d = (24*60*60)

print("{:02d}:{:02d}:{:02d}".format( d//(60*60), d%(60*60)//60, d%(60*60)%60))


