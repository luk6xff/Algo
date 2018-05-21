#Day 22: Grid Computing
#http://adventofcode.com/2016/day/22
import re

def getInput():
    with open('input.txt', 'r') as f:
        return f.readlines()

def solvePart1():
    inputList = getInput()
    nodeParams = []
    for line in inputList:
        line = line.rstrip()
        m = re.findall(r"(\d+)", line)
        if not m:
            continue
        nodeParams.append([int(param) for param in m])
    viablePairs = 0
    for i, node in enumerate(nodeParams):
        x, y, size, used, avail, usedPercentage = node
        if used > 0:
            for j in range(len(nodeParams)):
                if j == i:
                    continue
                xB, yB, sizeB, usedB, availB, usedPercentageB = nodeParams[j]
                if used <= availB:
                    viablePairs+=1
    return viablePairs     
            
                
def solvePart2():
    return "TO_BE_DONE"

print("PART 1, viable pairs of nodes: %d"%solvePart1())
print("PART 2, fewest number of steps %s"%solvePart2())
