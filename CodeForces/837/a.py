input();
words = list(input().split())

tot = 0

for word in words:
    tot = max(tot, len(list(filter(lambda a: a.isupper(), word))))

print (tot)
