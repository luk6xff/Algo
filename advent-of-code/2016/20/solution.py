#Day 20: Firewall Rules
#http://adventofcode.com/2016/day/20

def getInput():
    with open('input.txt', 'r') as f:
        return f.readlines()
        
def solvePart1():
    ipsBlocked = sorted([list(map(int, x.rstrip().split('-'))) for x in getInput()], key = lambda x:x[0])
    lowestIP  = 0
    for val in ipsBlocked:
        if lowestIP >= val[0] and lowestIP <= val[1]:
           lowestIP =  val[1]+1
    return lowestIP
    
def solvePart2():
    ipsBlocked = sorted([list(map(int, x.rstrip().split('-'))) for x in getInput()], key = lambda x:x[0])
    start = ipsBlocked[0][0]
    n = ipsBlocked[0][1]
    allowedIps = 0 + start
    for i in range(1, len(ipsBlocked)):
        if ipsBlocked[i][0] > n:
            allowedIps += ipsBlocked[i][0] - n -1
            n = ipsBlocked[i][1]
        if ipsBlocked[i][1] > n:
            n = ipsBlocked[i][1]         
    return allowedIps

print("PART 1, The lowest-valued IP %d"%solvePart1())
print("PART 2, Allowed IPs %d"%solvePart2())