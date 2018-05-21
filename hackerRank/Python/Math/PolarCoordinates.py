# /********************************************/
# /**PolarCoordinates*******/
# /********************************************/ 
#!/usr/bin/python

import sys
import cmath

if sys.version_info[0]<3: input =raw_input

def solution():
    complexData= complex(input())
    print(abs(complexData))
    print(cmath.phase(complexData))


solution()