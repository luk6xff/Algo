##/********************************************/
# /**Collections.deque()*******/
# /********************************************/	
#!/usr/bin/python
import sys
from collections import deque

if sys.version_info[0]<3: input=raw_input

def solution():
    numOfTests = int(input())
    d= deque()
    for i in range(0,numOfTests):
        data= input().split() 
        if len(data)==2:
            if(data[0]=="appendleft"):
                d.appendleft(int(data[1]))
            elif(data[0]=="append"):
                d.append(int(data[1]))
        elif len(data)==1:
            if(data[0]=="pop"):
                d.pop()
            elif(data[0]=="popleft"):
                d.popleft()
    for i in d:
        print(i,end=" ")

        
solution()