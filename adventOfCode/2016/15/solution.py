#Day 15: Timing is Everything
#http://adventofcode.com/2016/day/15
import re


def readInput():
    input = [line for line in open("input.txt", 'r')]
    return input
       
def solvePart1():
    paramsRe = re.compile(r'([0-9]+)')
    discs = []
    for line in readInput():
        discs.append(list(map(int, paramsRe.findall(line)[1:4])))
   
    startTime = 0
    while True:
        time = startTime
        capsuleNotCameOut = False
        for disc in discs:
            time+=1
            discPos = (disc[2]+time)%disc[0]
            if discPos != 0:
                capsuleNotCameOut = True
                break
        if capsuleNotCameOut:
           startTime+=1
        else:
            break
    print("Part1: First time: %d"%startTime)

def solvePart2():
    paramsRe = re.compile(r'([0-9]+)')
    discs = []
    for line in readInput():
        discs.append(list(map(int, paramsRe.findall(line)[1:4])))
    discs.append([11, 0, 0])
    startTime = 0
    while True:
        time = startTime
        capsuleNotCameOut = False
        for disc in discs:
            time+=1
            discPos = (disc[2]+time)%disc[0]
            if discPos != 0:
                capsuleNotCameOut = True
                break
        if capsuleNotCameOut:
           startTime+=1
        else:
            break
    print("Part2: First time: %d"%startTime) 
    
solvePart1()
solvePart2()
