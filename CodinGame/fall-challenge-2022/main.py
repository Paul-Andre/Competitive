import sys
import math
import random
from dataclasses import dataclass
from typing import Tuple

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

width, height = [int(i) for i in input().split()]

def debug(*args):
    print(*args, file=sys.stderr, flush=True)


@dataclass
class Tile:
    scrap_amount: int
    owner: int
    units: int
    recycler : int
    can_build: int
    can_spawn: int
    in_range_of_recycler: int

    num_units_as_checked: int = 0

    def is_walkable(self):
        return self.scrap_amount>0 and not self.recycler


@dataclass
class Unit:
    pos: tuple[int, int]
    target: tuple[int, int]



# game loop
while True:
    spawnable = []
    goable = []
    my_units = []

    
    tiles = [[None for _ in range(height)] for _ in range(width)]

    my_matter, opp_matter = [int(i) for i in input().split()]
    for y in range(height):
        for x in range(width):
            # owner: 1 = me, 0 = foe, -1 = neutral
            scrap_amount, owner, units, recycler, can_build, can_spawn, in_range_of_recycler = [int(k) for k in input().split()]
            tiles[x][y] = Tile(
                    scrap_amount=scrap_amount,
                    owner=owner,
                    units=units,
                    recycler =recycler ,
                    can_build=can_build,
                    can_spawn=can_spawn,
                    in_range_of_recycler=in_range_of_recycler)
            if can_spawn:
                spawnable.append((x,y))
            if scrap_amount > 0:
                goable.append((x,y))
            if owner == 1:
                for _ in range(units):
                    my_units.append((x,y))

    debug()
    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    command = "WAIT;"

    for y in range(height):
        for x in range(width):
            pass

    spawnable_scored = []
    for x,y in spawnable:
        score = 0
        for kx, ky in [(0,1), (1,0), (0,-1), (-1, 0)]:
            bx = x+kx
            by = y+ky
            if 0 <= bx <width and 0 <= by < height:
                tile = tiles[bx][by]
                if tile.is_walkable() and tile.owner!=1:
                    score += 1
        spawnable_scored.append((score, random.random(), x,y))


    for i in range(my_matter//10):
        score, _, x,y = max(spawnable_scored)
        command += f"SPAWN 1 {x} {y};"

    for ax, ay in my_units:
        choices = []
        for kx, ky in [(0,1), (1,0), (0,-1), (-1, 0)]:
            bx = ax+kx
            by = ay+ky
            if 0 <= bx <width and 0 <= by < height:
                tile = tiles[bx][by]
                if tile.is_walkable():
                    score = 0
                    if tile.owner != 1:
                        score += 1
                    choices.append((score, random.random(), bx,by))

        if choices:
            score, _, bx, by = max(choices)

            command += f"MOVE 1 {ax} {ay} {bx} {by};"
    
    print(command)



