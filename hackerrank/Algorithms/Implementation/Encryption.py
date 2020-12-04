# /********************************************/
# /**Encryption*******/
# /********************************************/ 
#!/usr/bin/python
 
import sys
from math import ceil,floor,sqrt
if sys.version_info[0]<3: input =raw_input
 
 
def solution():
    codedData=input().strip()
    L= len(codedData)
    columns= ceil(sqrt(L))
    rows= floor(sqrt(L))
    
    #print("L:"+str(L)+" columns:"+str(columns)+" rows:"+str(rows))
    tempList=list()
    for i in range(rows):
        try:
            tempList.append(codedData[i*columns:(i+1)*columns])
        except(IndexError):
            pass
    if((rows*columns)<L):
        tempList.append(codedData[(rows*columns):len(codedData)])
    #print("list:"+ str(tempList))
    s=str()
    if((rows*columns)<L):
        rows=rows+1
    for i in range(columns):      
        for x in range(rows):
            try:
                s+=tempList[x][i]
            except (IndexError):
                pass
        s=s+" "
    print(s)
                

solution()