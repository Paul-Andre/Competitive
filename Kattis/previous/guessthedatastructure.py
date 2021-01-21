import collections
import heapq

def tryQueue(commands):
    queue = collections.deque()
    for com,elem in commands:
        if com==1:
            queue.append(elem)
        if com==2:
            try:
                ee = queue.popleft()
            except IndexError:
                return False
            if ee!=elem:
                return False
    return True

def tryStack(commands):
    queue = collections.deque()
    for com,elem in commands:
        if com==1:
            queue.append(elem)
        if com==2:
            try:
                ee = queue.pop()
            except IndexError:
                return False
            if ee!=elem:
                return False
    return True

def tryPriority(commands):
    l = list()
    for com,elem in commands:
        if com==1:
            heapq.heappush(l, -elem)
        if com==2:
            try:
                ee = -heapq.heappop(l)
            except IndexError:
                return False
            if ee!=elem:
                return False
    return True

while(True):
    try:
        n = int(input())
    except EOFError:
        break
    commands = list()
    for _ in range(n):
        com, elem = map(int,input().split())
        commands.append((com, elem))
    q = tryQueue(commands)
    s = tryStack(commands)
    p = tryPriority(commands)

    if (q and not s and not p):
        print ("queue")
    elif (not q and s and not p):
        print ("stack")
    elif (not q and not s and p):
        print ("priority queue")
    elif (not q and not s and not p):
        print ("impossible")
    else:
        print ("not sure")
    


        

