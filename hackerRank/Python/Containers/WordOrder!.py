# /********************************************/

# /******************Word Order!******************/

# /********************************************/
#!/usr/bin/python
import sys
from collections import OrderedDict
if sys.version_info[0]>=3: raw_input=input

def solution():
    n = int(raw_input())
    dataDict = OrderedDict()
    if n<1 or n>100000 :
        return
    for i in range(n):
        key = raw_input()
        if key in dataDict:
            dataDict[key] +=1
        else: 
            dataDict[key] =1
    print(len(dataDict))   
    for i,j in dataDict.items():
        print(j,"", end="")
        
solution()	
