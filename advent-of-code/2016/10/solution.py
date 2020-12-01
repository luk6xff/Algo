#Day 10: Balance Bots
#http://adventofcode.com/2016/day/10
import re
from collections import defaultdict
import functools



def readInput():
    input = [line for line in open("input.txt", 'r')]
    return input
        
def solveParts12():
    input = readInput()
    bots = defaultdict(list)
    outputs = defaultdict(list)
    pipeline = {}
    for line in input:
        l = line.rstrip().split(" ")
        if "value" in l:
            bots[int(l[5])].append(int(l[1]))
        elif l[0] == "bot":
            rec1 = l[5]
            rec2 = l[10]
            pipeline[int(l[1])] = (rec1, int(l[6]), rec2, int(l[11]))
    while bots:
        for key, val in dict(bots).items():
            if len(val) == 2:
                rec1, rec1Num, rec2, rec2Num = pipeline[key]
                minVal, maxVal = sorted(val)
                if minVal ==17 and maxVal == 61:
                    print("PART1: NUM of the Bot: ",key)
                bots.pop(key)
                if rec1 == 'bot':
                    bots[rec1Num].append(minVal)
                else:
                    outputs[rec1Num].append(minVal)
                if rec2 == 'output':
                    outputs[rec2Num].append(maxVal)
                else:
                    bots[rec2Num].append(maxVal)
    print("PART2: ", functools.reduce(lambda x,y: x*y, outputs[0][:]) * 
                     functools.reduce(lambda x,y: x*y, outputs[1][:]) * 
                     functools.reduce(lambda x,y: x*y, outputs[2][:]))

solveParts12()
