#--- Day 5: Doesn't He Have Intern-Elves For This? ---
#http://adventofcode.com/2015/day/5
import re
import functools
import operator
from collections import defaultdict
import hashlib 


def readInput():
    input = [line for line in open("input.txt", 'r')]
    return input
        
def solvePart1():
    niceCounter = 0
    for line in readInput():
        #line = 'ugknbfddgicrmopnn'
        if len(re.findall(r'([a-z])', line)) > 0:
            if len(re.findall(r'([a|e|i|o|u])', line)) >= 3:
                if not any([True if x in line else False for x in ('ab', 'cd', 'pq', 'xy')]):
                    niceCounter+=1
    print("PART1: %d"%niceCounter)
    
def solvePart2():
    niceCounter = 0
    for line in readInput():
        #line = 'ugknbfddgicrmopnn'
        if len(re.findall(r'(?P<double>[a-z]{2}).*(?P=double)', line)) > 0:
            if len(re.findall(r'(?P<onesame>[a-z]{1}).{1}(?P=onesame)', line)) >0:
                niceCounter+=1
    print("PART2: %d"%niceCounter)

solvePart1()
solvePart2()
