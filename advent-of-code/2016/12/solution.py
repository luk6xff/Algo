#Day 12: Leonardo's Monorail
#http://adventofcode.com/2016/day/12
import re
from collections import defaultdict
import functools



def readInput():
    input = [line for line in open("input.txt", 'r')]
    return input

def performAssemblyBunnyInstructions(registers):
    pipeline = [instr.rstrip().split(" ") for instr in readInput()]
    pc = 0
    print(registers)
    while True:
        instr = pipeline[pc][0]
        if instr == 'cpy':
            if pipeline[pc][1] in registers:
                registers[pipeline[pc][2]] = registers[pipeline[pc][1]]
            else:
                registers[pipeline[pc][2]] = int(pipeline[pc][1])
        elif instr == 'inc':
                registers[pipeline[pc][1]]+=1
        elif instr == 'dec':
                registers[pipeline[pc][1]]-=1
        elif instr == 'jnz':
            if pipeline[pc][1] in registers:
                if registers[pipeline[pc][1]] == 0:
                    pc+=1
                else:
                    pc+=int(pipeline[pc][2])
            else:
                if pipeline[pc][1] == 0:
                    pc+=1
                else:
                    pc+=int(pipeline[pc][2])
        if pc == len(pipeline):
            break
        if instr != 'jnz':
            pc+=1
        
def solveParts12():
    cpuRegs = {'a':0, 'b':0, 'c':0, 'd':0}
    performAssemblyBunnyInstructions(cpuRegs)   
    print("PART 1, register a = %d"%cpuRegs['a'])
    
    cpuRegs = {'a':0, 'b':0, 'c':1, 'd':0}
    performAssemblyBunnyInstructions(cpuRegs)   
    print("PART 2, register a = %d"%cpuRegs['a'])
    
solveParts12()
