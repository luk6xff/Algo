#!/usr/bin/python
# /********************************************/
# /**Validating Email Addresses With a Filter*******/
# /********************************************/	
import sys
import math
import re
if sys.version_info[0]<3: input =raw_input

def fib(n):
    a, b = 0, 1
    for i in range(n):
        a, b = b, a+b
    return a
    
def solution():
    N= int(input())
    emailRegexPattern= "^[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z0-9._-]{1,3}$"
    print(sorted(list(filter(lambda email: re.match(emailRegexPattern, email)!= None ,list(input() for i in range(N))))))
solution()