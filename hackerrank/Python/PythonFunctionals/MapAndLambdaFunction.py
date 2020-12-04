#!/usr/bin/python
# /********************************************/
# /**Map and Lambda Function*******/
# /********************************************/	
import sys
import math

if sys.version_info[0]<3: input =raw_input

def fib(n):
    a, b = 0, 1
    for i in range(n):
        a, b = b, a+b
    return a
    
def solution():
    N= int(input())
    print(list(map(lambda a: a**3, [fib(i) for i in range(N)] )))
solution()