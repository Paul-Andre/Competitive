#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    a,b,c = s.split(":")
    d,e = c[:-2], c[-2:]
    hours = int(a)
    if hours==12:
        hours=0
    assert(e=="AM" or e=="PM")
    if e=="PM":
        hours+=12
    return f"{hours}:{b}:{d}"


if __name__ == '__main__':

    while(True):
        s = input()

        result = timeConversion(s)
        print(result)

