# /********************************************/
# /**Extra long factorials*******/
# /********************************************/ 
#!/usr/bin/python

import sys
import math

if sys.version_info[0]<3: input =raw_input

def solution():
    print(math.factorial(int(input())) )


solution()