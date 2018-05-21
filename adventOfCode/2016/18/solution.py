#Day 18: Like a Rogue
#http://adventofcode.com/2016/day/18

def getInput():
    with open('input.txt', 'r') as f:
        return f.readlines()

def isATrap(left, center, right):
    isTrap = False
    if (left == '^' and center == '^' and  right == '.'):
        isTrap = True     
    elif (left == '.' and center == '^' and  right == '^'):
        isTrap = True
    elif (left == '^' and center == '.' and  right == '.'):
        isTrap = True
    elif (left == '.' and center == '.' and  right == '^'):
        isTrap = True         
    return isTrap

def solvePart1And2(rowsNum):
    numOfRows = rowsNum
    numOfTraps = 0
    numOfSafes = 0
    rows = getInput()
    for _ in range(numOfRows - 1):
        rows.append(str())    
    for row in range(1, numOfRows):
        for i in range(len(rows[0])):
            if i == 0: 
                left = '.'
                right = rows[row -1][i+1]
            elif i == (len(rows[0]) -1): 
                right = '.'
                left = rows[row -1][i-1]
            else:
                left = rows[row -1][i-1]
                right = rows[row -1][i+1]
            center = rows[row -1][i]
            if(isATrap(left, center, right)):
                rows[row]+='^'
            else:
                rows[row]+='.'
    for row in rows:
        numOfTraps += row.count('^')
        numOfSafes += row.count('.')
    return  numOfSafes
 
          
 
  
print("PART 1, Num of safes: %d"%solvePart1And2(40))
print("PART 2, Num of safes: %d"%solvePart1And2(400000))



