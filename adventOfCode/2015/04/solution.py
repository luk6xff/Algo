#--- Day 4: The Ideal Stocking Stuffer ---
#http://adventofcode.com/2015/day/4
import re
import functools
import operator
from collections import defaultdict
import hashlib 


def readInput():
    input = [line for line in open("input.txt", 'r')]
    return input
        
def solvePart1():
    key = "".join(readInput())
    i = 0
    while True:
        fullKey = key + str(i)
        md5 = hashlib.md5(fullKey.encode('UTF-8'))
        if md5.hexdigest()[:5] == "00000":
            break
        i+=1
    print("PART1: %d"%i)
    
def solvePart2():
    key = "".join(readInput())
    i = 0
    while True:
        fullKey = key + str(i)
        md5 = hashlib.md5(fullKey.encode('UTF-8'))
        if md5.hexdigest()[:6] == "000000":
            break
        i+=1
    print("PART2: %d"%i)

solvePart1()
solvePart2()
