# /********************************************/

# /******************Piling Up!****************/

# /********************************************/
#!/usr/bin/python
import sys
from collections import deque
if sys.version_info[0]>=3: raw_input=input

def solution():
    T = int(raw_input())
    res = True
    for i in range(T):
        n = int(raw_input())
        lastLength= sys.maxsize
        res = "Yes"
        #if n<1 or n>100000 :
        #    return
        data = deque(map(int,raw_input().split()))
        while len(data) >0:
            item=0
            if data[0]>=data[-1]:
                item= data.popleft()
            else:
                item= data.pop()                   
            if item>lastLength:
                res="No"
                break
            lastLength= item      
        print(res)
       
solution()