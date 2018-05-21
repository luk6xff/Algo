# /********************************************/
# /**Set Mutations*******/
# /********************************************/ 
#!/usr/bin/python
import sys
 
 
if sys.version_info[0]<3: input =raw_input
 
def solution():
    nA = int(input())
    A = set(map(int, input().split()))
    nrOfOp =int(input())
    while nrOfOp>0:
        operation = list(input().split())
        dataSet= set(map(int, input().split()))
        if(operation[0]=='update'):
            A.update(dataSet)
        elif(operation[0]=='intersection_update'):
            A.intersection_update(dataSet)
        elif(operation[0]=='symmetric_difference_update'):
            A.symmetric_difference_update(dataSet)
        elif(operation[0]=='difference_update'):
            A.difference_update(dataSet)
        nrOfOp-=1
    print (sum(A))
 
solution()