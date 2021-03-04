from collections import defaultdict
from sys import stdin

n = int(stdin.readline())
balloons = [int(x) for x in stdin.readline().split()]

counter = 0


while len(balloons) != 0:
    max_height = max(balloons)
    to_drop = []
    for i in range(len(balloons)):
        #drop max balloon and decrease balloon height 1 and continue
        if (balloons[i] == max_height):
            to_drop.append(balloons[i])
            max_height-=1
            #remove all balloons that were once equal to the max height
    for j in to_drop:
        balloons.remove(j)
    counter+=1

print(counter)

