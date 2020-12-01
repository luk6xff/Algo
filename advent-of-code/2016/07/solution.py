#Day 7: Internet Protocol Version 7
#http://adventofcode.com/2016/day/7
import re


def readInput():
    input = [line for line in open("input.txt", 'r')]
    return input

def searchABBA(string):
    return any(a == d and b == c and a!=b for a,b,c,d in zip(string,string[1:],string[2:], string[3:]))
    
def searchABAandCompare(supernets, hypernets):
    for string in supernets:
        for bracketsStr in hypernets:
            listStr = [a+b+c for a,b,c in zip(string,string[1:],string[2:]) if a == c and a != b]
            listBrackets = [a+b+c for a,b,c in zip(bracketsStr,bracketsStr[1:],bracketsStr[2:]) if a == c and a != b]
            for lStr in listStr:
                for lBStr in listBrackets:
                    if lStr == lBStr[1]+lBStr[0]+lBStr[1]:
                        return True   
    return False
        
def solvePart1():
    input = readInput()
    numOfIPs = 0
    reCompiledBrackets = re.compile(r'\[([a-z]+)\]')
    for line in input:
        result = reCompiledBrackets.findall(line)
        isIP = True
        for r in result:
            line = line.replace('['+r+']', ' ')    
        line = line.split(' ')
        if all(searchABBA(r) == False  for r in result):
            if any(searchABBA(l) == True for l in line):
                numOfIPs += 1
    print("NUM of IPS: " ,numOfIPs)

def solvePart2():
    input = readInput()
    numOfIPs = 0
    reCompiledBrackets = re.compile(r'\[([a-z]+)\]')
    for line in input:
        result = reCompiledBrackets.findall(line)
        for r in result:
            line = line.replace('['+r+']', ' ')    
        line = line.split(' ')
        if searchABAandCompare(line, result):                  
            numOfIPs += 1
    print("NUM of IPS: " ,numOfIPs)   
    
solvePart1()
solvePart2()
