#--- Day 7: Some Assembly Required ---
#http://adventofcode.com/2015/day/7
import re
import functools
import operator
from collections import defaultdict
import hashlib 


def getInput():
    with open('input.txt', 'r') as f:
        return f.readlines()
        
def solvePart1():
    instructions = getInput()
    load = re.compile(r'^([0-9]*)\s->\s([a-z]+)$')
    nott = re.compile(r'^NOT\s([a-z]+)\s->\s([a-z]+)$')
    shift = re.compile(r'^([a-z]+)\s(LSHIFT|RSHIFT)\s([0-9]*)\s->\s([a-z]+)$')
    logic = re.compile(r'^([a-z]+)\s(AND|OR)\s([a-z]+)\s->\s([a-z]+)$')
    registers = defaultdict()
    for instr in instructions:
        li = load.search(instr)
        ni = nott.search(instr)
        shi = shift.search(instr)
        loi = logic.search(instr)
        if li:
            registers[li.group(2)] = int(li.group(1))
            print("LI")
        elif ni:
            registers[ni.group(2)] = ~registers[ni.group(1)]
            print("NI")
        elif shi:
            if shi.group(2) == "LSHIFT": 
                registers[shi.group(4)] = registers[shi.group(1)] >> int(shi.group(3))
            else:
                registers[shi.group(4)] = registers[shi.group(1)] << int(shi.group(3))
            print("SHIFT")
        elif loi:
            if loi.group(2) == "AND": 
                registers[loi.group(4)] = registers[loi.group(1)] & registers[loi.group(3)]
            else:
                registers[loi.group(4)] = registers[loi.group(1)] | registers[loi.group(3)]
            print("AND")
    print(registers)            
    return 0

    
def solvePart2():
    a = 0         
    return a

print("PART 1: %d"%solvePart1())
print("PART 2: %d"%solvePart2())
