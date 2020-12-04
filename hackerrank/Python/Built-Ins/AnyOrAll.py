#!/usr/bin/python
# /********************************************/
# /**Any or All*******/
# /********************************************/	
import sys


if sys.version_info[0]<3: input =raw_input

def solution():
    dummy =input()
    data= list(map(int,input().split(" ")))
    if(all(x>0 for x in data) is True):
        if(any(str(y)==str(y)[::-1] for y in data) is True):
                print("True")
                return   
    print("False")

solution()