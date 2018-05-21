# /********************************************/
# /**Manasa and Stones*******/
# /********************************************/ 
#!/usr/bin/python
 
import sys
import math
if sys.version_info[0]<3: input =raw_input
 
 

def solution():
    T=int(input())
    for i in range(T):
        n=int(input()) #nrOfStones
        a=int(input())
        b=int(input())
        dataSet= set()
        for j in range(n-1,0,-1):
            dataSet.add(a*j+b*(n-1-j))
        for j in range(n-1,0,-1):
            dataSet.add(b*j+a*(n-1-j))
        dataList= str(sorted(dataSet,reverse=False)).replace(",", "")
        print(dataList.strip('[]'))

           
        
        
solution()

