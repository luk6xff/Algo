# /********************************************/
# /**Service Lane*******/
# /********************************************/ 
#!/usr/bin/python
 
import sys
import math
if sys.version_info[0]<3: input =raw_input
 
 
def checkMaxVehicleAllowed(serviceLane):
    maxVeh=3 #car
    for i in serviceLane:
        if i <maxVeh:
            maxVeh=i
    return maxVeh
    
def solution():
    N,T= map(int,input().split())
    widthList= list(map(int,input().split()))
    while T:
        i,j= map(int,input().split())
        if i<0 or j<0 or i>=N or j>=N:
            return
        print(checkMaxVehicleAllowed(widthList[i:j+1]))
        T-=1
solution()
