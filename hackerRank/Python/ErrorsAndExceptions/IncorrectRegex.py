#!/usr/bin/python
# /********************************************/
# /**Incorrect Regex*******/
# /********************************************/	
import sys
import re

if sys.version_info[0]<3: input =raw_input

def solution():
    n= int(input())
    for _ in range(n):        
        try:
            re.compile(input())
            print('True')
        except Exception as e:
            print('False')
solution()