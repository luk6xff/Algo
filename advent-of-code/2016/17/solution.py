#Day 17: Two Steps Forward
#http://adventofcode.com/2016/day/17
import hashlib
import re
from collections import deque


def getDoorsState(currentPath = None):
    passcode = "veumntbg"
    if currentPath is None:
       currentPath = ""
    key = passcode + str(currentPath)
    md5 = hashlib.md5(key.encode("UTF-8")).hexdigest()
    return [1 if c in "bcdef" else 0 for c in md5[:4]]
      
class Point:
    def __init__(self,x, y):
        self.x = x
        self.y = y

directions = [
                Point(0, -1), #'U'
                Point(0, 1), #'D'
                Point(-1,0), #'L'
                Point(1 ,0)  #'R'
             ]

directPaths = ('U', 'D' ,'L' , 'R')
def solvePart1():
    
    q = deque()
    src = Point(0,0)
    dst = Point(3,3)
    q.append((src, 0, "")) #init node
    
    while len(q) is not 0:
        curr = q.popleft()
        currDist = curr[1]
        currPoint = curr[0] #current Position
        pathTaken = curr[2]
        if currPoint.x == dst.x and currPoint.y == dst.y:
            print("PART 1, shortest path: %d"%currDist)
            print("PART 1, pathTaken: %s"%pathTaken)
            break
        directs = getDoorsState(pathTaken)
        for i, direct in enumerate(directs):
            if direct:
                newPoint = Point(currPoint.x + directions[i].x, currPoint.y + directions[i].y)
                #print("NEW POINT: x= " + str(newPoint.x) +"y= "+ str(newPoint.y))
                if newPoint.x in (0,1,2,3) and newPoint.y in (0,1,2,3):
                    path = pathTaken+directPaths[i]
                    q.append((newPoint, currDist+1, path))    
                
  
def solvePart2():
    q = deque()
    src = Point(0,0)
    dst = Point(3,3)
    q.append((src, 0, "")) #init node
    allPaths = []
    while q:
        curr = q.popleft()
        currDist = curr[1]
        currPoint = curr[0] #current Position
        pathTaken = curr[2]
        directs = getDoorsState(pathTaken)
        for i, direct in enumerate(directs):
            if direct:
                newPoint = Point(currPoint.x + directions[i].x, currPoint.y + directions[i].y)
                if newPoint.x in (0,1,2,3) and newPoint.y in (0,1,2,3):
                    path = pathTaken+directPaths[i]
                    if newPoint.x == dst.x and newPoint.y == dst.y:
                        allPaths.append(currDist+1)
                    else:
                        q.append((newPoint, currDist+1, path))                   
    print("PART 2, longetsPath %d"%allPaths[-1])
 
  
solvePart1()
solvePart2()



