#--- Day 6: Probably a Fire Hazard ---
#http://adventofcode.com/2015/day/6
import re
import functools
import operator
from collections import defaultdict
import hashlib 


def readInput():
    input = [line for line in open("input.txt", 'r')]
    return input
        
def solvePart1():
    counter = 0
    lights = [[0 for _ in range(1000)] for _ in range(1000)]
    for line in readInput():
        cmd = line.rstrip().split()
        if 'toggle' in cmd:
            x1, y1 = map(int, cmd[1].split(','))
            x2, y2 = map(int, cmd[3].split(','))
        elif 'on' in cmd or 'off' in cmd:
            x1, y1 = map(int, cmd[2].split(','))
            x2, y2 = map(int, cmd[4].split(','))        
        
        for y in range(y1, y2+1):
            for x in range(x1, x2+1):               
                if 'toggle' in cmd:
                   lights[y][x]^= 1 
                elif 'on' in cmd: 
                   lights[y][x] = 1     
                elif 'off' in cmd:
                   lights[y][x] = 0         
        
    for y in lights:
        for x in y:
            if x == 1:
                counter+=1             
    print("PART1: %d"%counter)
    
def solvePart2():
    brightness = 0
    lights = [[0 for _ in range(1000)] for _ in range(1000)]
    for line in readInput():
        cmd = line.rstrip().split()
        if 'toggle' in cmd:
            x1, y1 = map(int, cmd[1].split(','))
            x2, y2 = map(int, cmd[3].split(','))
        elif 'on' in cmd or 'off' in cmd:
            x1, y1 = map(int, cmd[2].split(','))
            x2, y2 = map(int, cmd[4].split(','))        
        
        for y in range(y1, y2+1):
            for x in range(x1, x2+1):               
                if 'toggle' in cmd:
                    lights[y][x]+= 2 
                elif 'on' in cmd: 
                    lights[y][x]+= 1     
                elif 'off' in cmd:
                    lights[y][x]-= 1 
                    if lights[y][x] < 0:
                        lights[y][x] = 0  
        
    for y in lights:
        for x in y:
            brightness+=x             
    print("PART2: %d"%brightness)

solvePart1()
solvePart2()
