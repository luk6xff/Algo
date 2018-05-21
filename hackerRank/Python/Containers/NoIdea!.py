# /********************************************/

# /******************No Idea!******************/

# /********************************************/	
#!/usr/bin/python
import sys

if sys.version_info[0]>=3: raw_input=input

def solution():
    happiness=0
    n,m = map(int,raw_input().strip().split(' '))
    if n<1 or m>100000 or m<1 or m>100000 :
        return
    dataSet= map(int,raw_input().split())
    #print(dataSet)
    A= set(map(int,raw_input().strip().split(' ')))
    B= set(map(int,raw_input().strip().split(' ')))
    for i in dataSet:
        #if i in A:
        #    happiness+=1 
        #if i in B:
        #    happiness-=1 
        happiness+=((i in A)-(i in B))
    print(happiness)
        
solution()

