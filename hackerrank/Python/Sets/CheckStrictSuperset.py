# /********************************************/
# /**Check Strict Superset*******/
# /********************************************/ 
#!/usr/bin/python
import sys
from collections import Counter 
 
if sys.version_info[0]<3: input =raw_input

def solution():
    superset =set(map(int, input().split()))
    nrOfSets= int(input())
    while(nrOfSets>0):
        setData=set(map(int, input().split()))
        if(not(setData==setData.intersection(superset))):
            print("False")
            return
        nrOfSets-=1
    print("True") 
solution()