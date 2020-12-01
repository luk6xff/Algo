#--- Day 2: I Was Told There Would Be No Math ---
#http://adventofcode.com/2015/day/2
import re
import functools
import operator



def readInput():
    input = [line for line in open("input.txt", 'r')]
    return input
        
def solvePart1():
    input = readInput()
    totalSquare = 0
    for i in input:
        l, w, h = ll = list(map(int, i.rstrip().split('x')))
        ll[0] = 2*l*w
        ll[1] = 2*w*h
        ll[2] = 2*h*l
        totalSquare+= sum(ll) + sorted(ll)[0]/2
    print("PART1: %d"%totalSquare)
    
def solvePart2():
    input = readInput()
    totalRibbonFeets = 0
    for i in input:
        ll = sorted(list(map(int, i.rstrip().split('x'))))
        totalRibbonFeets+= 2*ll[0] + 2*ll[1] + functools.reduce(operator.mul, ll)
    print("PART2: %d"%totalRibbonFeets)

solvePart1()
solvePart2()
