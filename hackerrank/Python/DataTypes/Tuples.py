# /********************************************/

# /**Tuples*******/

# /********************************************/
import sys
nrOfNum = int(input())
data= input().split(" ")
tuple=()
for i in range(0,nrOfNum):
    tuple =tuple +(int(data[i]),)
print(hash(tuple))  
