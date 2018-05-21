# /********************************************/
# /**Set .discard(), .remove() & .pop()*******/
# /********************************************/ 
#!/usr/bin/python
import sys
 
 
if sys.version_info[0]<3: input =raw_input
 
def solution():
n = int(input())
s = set(map(int, input().split()))
nrOfOp =int(input())
while nrOfOp>0:
    operation = list(input().split())
    if(operation[0]=='pop'):
        s.pop()
    elif(operation[0]=='remove'):
        s.remove(int(operation[1]))
    elif(operation[0]=='discard'):
        s.discard(int(operation[1]))
    nrOfOp-=1
print (sum(s))
 
solution()