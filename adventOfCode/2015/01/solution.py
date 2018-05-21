#--- Day 1: Not Quite Lisp ---
#http://adventofcode.com/2015/day/1
import re
from collections import defaultdict
import functools



def readInput():
    input = [line for line in open("input.txt", 'r')]
    return input
        
def solveParts12():
    input = readInput()
    print("PART1: ", input[0].count('(') - input[0].count(')'))
    floor = 0
    for i, ch in enumerate(input[0]):
        if ch == '(':
            floor+=1
        else:
            floor-=1
        if floor == -1:
            print("PART2: ",i+1)
            break
solveParts12()
