#https://www.hackerrank.com/challenges/saveprincess2
def nextMove(n,r,c,grid):
    move = {'d':'DOWN', 'u':'UP', 'r':'RIGHT', 'l':'LEFT', 'i':'INVALID'}
    res = move['i']
    m = {'y':r, 'x':c}
    p = {'y':0, 'x':0}
    for i, row in enumerate(grid):
        for j, c in enumerate(row):
            if c == 'p':
                p['y'] = i
                p['x'] = j
    xDiff = m['x'] - p['x']
    yDiff = m['y'] - p['y']
    
    biggerDiff = max(abs(xDiff), abs(yDiff))
    if biggerDiff == abs(xDiff):
        if(m['x'] > p['x']):
            res = move['l']
        elif(m['x'] < p['x']):
            res = move['r']    
    else:
        if(m['y'] > p['y']):
            res = move['u']
        elif(m['y'] < p['y']):
            res = move['d']
    return res
    
n = int(input())
r,c = [int(i) for i in input().strip().split()]
grid = []
for i in range(0, n):
    grid.append(input())

print(nextMove(n,r,c,grid))
