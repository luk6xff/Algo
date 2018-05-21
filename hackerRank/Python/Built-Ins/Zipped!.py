#!/usr/bin/python
# /********************************************/
# /**Zipped!*******/
# /********************************************/	
import sys


if sys.version_info[0]<3: input =raw_input

#1st way:
def solution():
    N,X =map(int,input().split())
    data =list()
    for _ in range(X):
        data.append(list(map(float,input().split(" "))))
    for i in range(N):
        suma=0
        for j in range(X):
            suma+=data[j][i]
        print("%.2f"%(suma/X))
            
#2nd way:
def solution():
    N,X =map(int,input().split())
    zipped= zip(*[[float(i) for i in input().split(' ')]for _ in range(X)])
    #print(*zipped)
    for val in zipped:
        print(sum(val)/len(val))
            
            
            
            
solution()