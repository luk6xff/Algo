# /********************************************/
# /**Plus Minus*******/
# /********************************************/ 
#!/usr/bin/python

import sys
import cmath

if sys.version_info[0]<3: input =raw_input

def solution():
    N= int(input())
    data = list(map(int,input().split()))
    listaLess = []
    listaMore = []
    listaZero=[]
    for x in data: 
        if x<0:
            listaLess.append(x)
        if x>0:
            listaMore.append(x)
        if x==0:
            listaZero.append(x)
    print(len(listaMore)/N)
    print(len(listaLess)/N)
    print(len(listaZero)/N)


solution()