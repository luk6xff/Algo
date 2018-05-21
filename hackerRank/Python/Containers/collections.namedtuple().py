## /********************************************/
# /**Collections.namedtuple()*******/
# /********************************************/	
#!/usr/bin/python
import sys
from collections import namedtuple
if sys.version_info[0]<3: input=raw_input

def solution():    
    numOfData= int(input())
    columnNamesStr =str(input())
    columnNames= list(map(str,columnNamesStr.split()))
    marksIdx=columnNames.index('MARKS') 
    Spreadsheet = namedtuple('Spreadsheet',columnNames)
    avg=0
    for i in range(0,numOfData):
        avg+= int(list(map(str,input().split()))[marksIdx])
    print(avg/numOfData)  
            
solution()



#4 lines solution
from collections import namedtuple
numOfData = int(input())
Student = namedtuple("Student",input().split())
print (sum(int(Student(*input().split()).MARKS) for i in range(numOfData))/float(numOfData))