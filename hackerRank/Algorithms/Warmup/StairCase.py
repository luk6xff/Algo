# /********************************************/
# /**Staircase*******/
# /********************************************/ 
#!/usr/bin/python

import sys
import cmath

if sys.version_info[0]<3: input =raw_input

def solution():
    N= int(input())
    for x in range(N):
        print(" "* (N-x-1) +"#"* (x+1) )


solution()