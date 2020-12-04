# /********************************************/
# /**Set.add()*******/
# /********************************************/	
#!/usr/bin/python
import sys


if sys.version_info[0]<3: input =raw_input

def solution():
    stampsSet=set()
    numOfStamps= int(input())
    for i in range(numOfStamps):
        stampsSet.add(str(input()))
    print (len(stampsSet))

solution()