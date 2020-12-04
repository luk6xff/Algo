##/********************************************/
# /**Collections.OrderedDict()*******/
# /********************************************/	
#!/usr/bin/python
import sys
from collections import OrderedDict
if sys.version_info[0]<3: input=raw_input

def solution():    
    numOfData= int(input())
    orderedDict= OrderedDict()
    for i in range(0,numOfData):
        items=input().split()
        if(len(items)>2):
            item_name= items[0]+" "+items[1]
            net_price=int(items[2])
        else:
            item_name= items[0]
            net_price=int(items[1])
        if(item_name in orderedDict):
            orderedDict[item_name]+=net_price
        else:
            orderedDict[item_name]=net_price
    for keys,values in orderedDict.items():
        print(keys,values)

            
solution()