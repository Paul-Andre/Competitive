a = input().split()
d = int(a[0])
if len(a) == 2:
    p = list(a[1])
else:
    p = []

layer = 0
position = 0
for v in p:
    layer +=1
    position= position*2
    if v == 'L':
        position+=1

nodes_above = 2**layer-1
nodes_on_right = 2**layer-position-1
nodes_tot = 2*2**d-1
print(nodes_tot - nodes_above - nodes_on_right)



