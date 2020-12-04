# /********************************************/
# /**Cut the sticks*******/
# /********************************************/ 
#!/usr/bin/python
 
import sys
import math
if sys.version_info[0]<3: input =raw_input
 
 

def solution():
    N=input()
    sticksList= list(map(int,input().split()))
    while len(sticksList)>0:
        minVal= min(sticksList)
        for i in range(len(sticksList)):
            sticksList[i]=sticksList[i]-minVal
        print(len(sticksList))
        sticksList= [i for i in sticksList if i>0]
        
solution()

