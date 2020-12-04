# /********************************************/
# /**Sherlock and Squares*******/
# /********************************************/ 
#!/usr/bin/python
 
import sys
import math
if sys.version_info[0]<3: input =raw_input
 
def solution():
    T =int(input())
    while T:
        A,B= map(int,input().split())
        print(math.floor(math.sqrt(B))-math.floor(math.sqrt(A-1)))
        T-=1
solution()