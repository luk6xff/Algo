# /********************************************/
# /**Introduction to Sets*******/
# /********************************************/	
#!/usr/bin/python
import sys


if sys.version_info[0]<3: input =raw_input

def solution():
    dummy= int(input())
    dataSet= set(map(int, (input().split(" "))))
    print (sum(dataSet)/len(dataSet))

solution()