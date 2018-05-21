#Day 23: Safe Cracking
#http://adventofcode.com/2016/day/23

import re
from collections import defaultdict
import functools



def readInput():
    input = [line for line in open("input.txt", 'r')]
    return input

def performAssemblyBunnyInstructions(registers):
    pipeline = [instr.rstrip().split(" ") for instr in readInput()]
    pc = 0
    print(pipeline)
    while True:
        instr = pipeline[pc][0]
        arg1 = pipeline[pc][1]
        try:
            arg2 = 'INVALID'
            arg2 = pipeline[pc][2]
        except:
            pass
        if instr == 'cpy' and arg2 in registers:
            if arg1 in registers:
                registers[arg2] = registers[arg1]
            else:
                registers[arg2] = int(arg1)
        elif instr == 'inc' and arg1 in registers:
                registers[arg1] += 1
        elif instr == 'dec' and arg1 in registers:
                registers[arg1] -= 1
        elif instr == 'jnz':
            if arg1 in registers:
                if registers[arg1] <= 0:
                    pc += 1
                else:
                    try:
                        pc += registers[arg2]
                    except:
                        pc += int(arg2)
            else:
                if arg1 <= 0:
                    pc += 1
                else:     
                    try:
                        pc += registers[arg2]
                    except:
                        pc += int(arg2)
        elif instr == 'tgl':
            if arg1 in registers:
                index = pc+registers[arg1]
                if index >= len(pipeline):
                    pc+=1
                    continue
                if registers[arg1] == 0:
                    pipeline[pc][0] = 'inc'
                    pipeline[pc][1] = arg1
                else:
                    try:
                        pipeline[index][2] = pipeline[index][2]
                        if pipeline[index][0] == 'jnz':
                            pipeline[index][0] = 'cpy'
                        else:
                            pipeline[index][0] = 'jnz'
                    except:                   
                        if pipeline[index][0] == 'inc':
                            pipeline[index][0] = 'dec'
                        else:
                            pipeline[index][0] = 'inc'                
            else:
                index = pc+arg1
                if index >= len(pipeline):
                    pc+=1
                    continue
                if arg1 == 0:
                    pipeline[pc][0] = 'inc'
                    pipeline[pc][1] = arg1
                else:
                    try:
                        pipeline[index][2] = pipeline[index][2]
                        if pipeline[index][0] == 'jnz':
                            pipeline[index][0] = 'cpy'
                        else:
                            pipeline[index][0] = 'jnz'
                    except:                   
                        if pipeline[index][0] == 'inc':
                            pipeline[index][0] = 'dec'
                        else:
                            pipeline[index][0] = 'inc'   
        if pc >= len(pipeline):
            break
        if instr != 'jnz':
            pc+=1
        
def solveParts12():
    cpuRegs = {'a':7, 'b':0, 'c':0, 'd':0}
    performAssemblyBunnyInstructions(cpuRegs)   
    print("PART 1, register a = %d"%cpuRegs['a'])
    
    cpuRegs = {'a':12, 'b':0, 'c':0, 'd':0}
    performAssemblyBunnyInstructions(cpuRegs)   
    print("PART 2, register a = %d"%cpuRegs['a'])
    
solveParts12()
