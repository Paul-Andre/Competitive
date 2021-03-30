from collections import defaultdict
from collections import Counter
n = int(input())
understands = defaultdict(set)
speaks = defaultdict(set)
for _ in range(n):
    a = input().split()
    speaks[a[1]].add(a[0])
    for lang in a[1:]:
        understands[lang].add(a[0])

g = defaultdict(set)
h = defaultdict(set)
for lang, chars in speaks.items():
    for c in chars:
        for c2 in understands[lang]:
            g[c].add(c2)
            h[c2].add(c)

kosaraju = []
components = Counter()
def traverse1(i):
    if i in vis:
        return
    vis.add(i)
    for j in g[i]:
        traverse1(j)
    kosaraju.append(i)

def traverse2(i, comp):
    if i in vis:
        return
    vis.add(i)
    components[comp]+=1
    for j in h[i]:
        traverse2(j, comp)


vis = set()
for c in g.keys():
    traverse1(c)


vis = set()
for c in reversed(kosaraju):
    traverse2(c, c)

print(n- components.most_common()[0][1])



