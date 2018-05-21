#--- Day 3: Perfectly Spherical Houses in a Vacuum ---
#http://adventofcode.com/2015/day/3
import re
import functools
import operator
from collections import defaultdict 


def readInput():
    input = [line for line in open("input.txt", 'r')]
    return input
        
def solvePart1():
    input = readInput()
    house = set()
    houses = defaultdict(list)
    housesNum = 1 #which get more than one present
    x = 0
    y = 0
    houses[(x,y)].append(1)
    for inp in input:
        for dir in inp:
            if dir == '^':
                y+=1
            elif dir == 'v':
                y-=1
            elif dir == '>':
                x+=1
            elif dir == '<':
                x-=1
            houses[(x,y)].append(1)
            if len(houses[(x,y)]) == 1:
                housesNum += 1   
    print("PART1: %d"%housesNum)
    
def solvePart2():
    input = readInput()
    house = set()
    houses = defaultdict(list)
    housesNum = 1 #which get more than one present
    xS = yS = xR = yR = 0
    maps = {0:[xS, yS] , 1:[xR, yR]}
    santaOrRobo = 0 #santa-0, robo-1
    houses[(xS,yS)].append(1)
    for inp in input:
        for dir in inp:
            if dir == '^':
                maps[santaOrRobo][1]+=1
            elif dir == 'v':
                maps[santaOrRobo][1]-=1
            elif dir == '>':
                maps[santaOrRobo][0]+=1
            elif dir == '<':
                maps[santaOrRobo][0]-=1
            x,y = maps[santaOrRobo]
            houses[(x,y)].append(1)
            if len(houses[(x,y)]) == 1:
                housesNum += 1
            santaOrRobo = not santaOrRobo
    print("PART2: %d"%housesNum)

solvePart1()
solvePart2()
