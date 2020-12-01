#Day 19: An Elephant Named Joseph
#http://adventofcode.com/2016/day/19

def getInput():
    with open('input.txt', 'r') as f:
        return f.readlines()

class Node:
    def __init__(self, idNum):
        self.idNum = idNum
        self.next = None
        self.previous = None
        
    def delete(self):
        self.previous.next = self.next
        self.next.previous = self.previous
        
def solvePart1():
    numOfElves = int(getInput()[0])
    
    elfs = list(map(Node, range(1, numOfElves+1)))
    for i in range(numOfElves):
        elfs[i].next = elfs[(i+1)%numOfElves]
        elfs[i].previous = elfs[(i-1)%numOfElves]
    
    startNode = elfs[0]
    for i in range(0, numOfElves-1):
        startNode.next.delete()
        startNode = startNode.next
    return startNode.idNum
    

def solvePart2():
    numOfElves = int(getInput()[0])
    
    elfs = list(map(Node, range(1, numOfElves+1)))
    for i in range(numOfElves):
        elfs[i].next = elfs[(i+1)%numOfElves]
        elfs[i].previous = elfs[(i-1)%numOfElves]
    
    startNode = elfs[0]
    
    print(int(numOfElves / 2))
    middleNode = elfs[ int(numOfElves / 2)]
    for i in range(0, numOfElves-1):
        middleNode.delete()
        middleNode = middleNode.next
        if (i -1)%2 == 1:
            middleNode = middleNode.next
        startNode = startNode.next
    return startNode.idNum

#borrowed from https://www.reddit.com/r/adventofcode/comments/5j4lp1/2016_day_19_solutions/
def solvePart(num):
    if num == 1:
        return 1
    p = 1
    while 3 * p < num:
        p *= 3
    if num <= 2 * p:
        return num - p
    r = num % p
    if r == 0:
        r = p
    return num - p  + r
    
print("PART 1, Elf that gets all the presents: %d"%solvePart1())
print("PART 2, Elf that gets all the presents: %d"%solvePart2())
print("PART 1, Elf that gets all the presents: %d"%solvePart(3005290))




