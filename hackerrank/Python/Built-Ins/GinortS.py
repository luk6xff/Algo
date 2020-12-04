# /********************************************/
# /**ginortS*******/
# /********************************************/	
# compareFunc returns -1, less than y so it's stored before x (reverse =False)
#!/usr/bin/python
import sys
import calendar
import functools

if sys.version_info[0]<3: input =raw_input
    
def compareFunc(x, y):
    if x.islower() or y.islower():
        if x.islower() and y.islower():
            return ord(x)-ord(y)
        if x.islower(): 
            return -1
        if y.islower():
            return 1
    if x.isupper() or y.isupper():
        if x.isupper() and y.isupper():
            return ord(x)-ord(y)
        if x.isupper(): 
            return -1
        if y.isupper():
            return 1 
    if x.isdigit() or y.isdigit():
        if ord(x)%2==ord(y)%2: 
            return ord(x)-ord(y)
        if ord(x)%2==1: 
            return -1
        if ord(y)%2==1: 
            return 1
    return None

def solution():
    dataStr= input()
    print(functools.reduce(lambda x,y:x+y,sorted(dataStr,key=functools.cmp_to_key(compareFunc))))

solution()