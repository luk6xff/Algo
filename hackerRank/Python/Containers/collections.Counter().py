# /********************************************/

# /**collections.Counter()*******/

# /********************************************/	
#!/usr/bin/python
import sys
from collections import Counter

if sys.version_info[0]<3: input=raw_input

def solution():
    dummy= input()
    sizeOfShoes = list(map(int,input().split()))
    counterDict = Counter(sizeOfShoes)
    totalMoneyEarned =0
    for i in range(0,int(input())):
        shoeSize,price= map(int,input().split())
        if(counterDict[shoeSize] >0):
            counterDict[shoeSize]-=1
            totalMoneyEarned+=price
    print(totalMoneyEarned)    
            
solution()