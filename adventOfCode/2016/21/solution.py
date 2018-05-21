#Day 21: Scrambled Letters and Hash
#http://adventofcode.com/2016/day/21
from itertools import permutations

def getInput():
    with open('input.txt', 'r') as f:
        return f.readlines()

def rotateRight(l,n):
  return l[-n:] + l[:-n]

def rotateLeft(l,n):
  return l[n:] + l[:n]
    
def solvePart1(inpString):
    inputList = getInput()
    l = list(inpString)
    for line in inputList:
        spl = line.split()
        indexes = [int(x) for x in spl if x.isdigit()]
        if line.startswith('swap position'):
          x,y = indexes
          l[x],l[y] = l[y],l[x]
        elif line.startswith('swap letter'):
          x,y = spl[2],spl[-1]
          i,j = l.index(x), l.index(y)
          l[i],l[j] = l[j],l[i]
        elif line.startswith('rotate left'):
          x = indexes[0]
          l = rotateLeft(l,x)
        elif line.startswith('rotate right'):
          x = indexes[0]
          l = rotateRight(l,x)
        elif line.startswith('rotate based'):
          c = spl[-1]
          i = l.index(c)
          i += (i>=4) + 1
          l = rotateRight(l,i%len(l))
        elif line.startswith('reverse'):
          x,y = indexes
          l[x:y+1] = l[x:y+1][::-1]
        else: #move
          x,y = indexes
          a = l.pop(x)
          l = l[:y]+[a]+l[y:]
    return ''.join(l)
    
def solvePart2():
    for password in permutations('abcdefgh'):
        if solvePart1(password) == 'fbgdceah':
            return ''.join(password)  
    return "NOT_FOUND"

print("PART 1, scrambled password: %s"%solvePart1('abcdefgh'))
print("PART 2, un-scrambled password %s"%solvePart2())
