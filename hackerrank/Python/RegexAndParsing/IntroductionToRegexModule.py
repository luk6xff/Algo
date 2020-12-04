#!/usr/bin/python
# /********************************************/
# /**Introduction to Regex Module*******/
# /********************************************/	
import sys
import math
import re

if sys.version_info[0]<3: input =raw_input

N=int(input())
while(N):
    num = input()
    try:
        numF=float(num)
        if numF ==0:
            print('False') 
        elif re.search('^([+|-]{0,1}[0-9]*[\.{1}[0-9]+]?)$',num):
            print('True')
        else:
            print('False')
    except:
        print('False')  
    N=N-1



