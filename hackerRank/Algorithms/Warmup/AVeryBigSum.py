# /********************************************/
# /**A Very Big Sum*******/
# /********************************************/ 
#!/usr/bin/python

import sys

if sys.version_info[0]<3: input =raw_input

def solution():
    dummy =input()
    print(sum(tuple(map(int,input().split()))))

solution()
