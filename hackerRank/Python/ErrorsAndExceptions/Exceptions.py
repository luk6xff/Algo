#!/usr/bin/python
# /********************************************/
# /**Exceptions*******/
# /********************************************/	
import sys


if sys.version_info[0]<3: input =raw_input

#1st way:
def solution():
    dummy= int(input())
    for _ in range(dummy):
        
        try:
            a,b= map(int,input().split())
            print(a//b)
        except ZeroDivisionError as e:
            print("Error Code: "+str(e))
        except ValueError as e:
            print("Error Code: "+str(e))
solution()