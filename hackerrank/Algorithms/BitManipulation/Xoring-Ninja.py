#!/usr/bin/python
import itertools
import functools


stopRange= (10**9+7)

#too slow for big input data
def powerSetList1(iterable):
    s = list(iterable)
    return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(len(s)+1))

def powerSetList2(lst):
    r = [[]]
    for e in lst:
        r += [x+[e] for x in r]
    return r

def slowSolution():
    for _ in range(int(input())):
        input()
        inputSet= list(map(int, input().split()))
        xorSum=0;
        for _set in powerSetList2(inputSet):
            if(len(_set)==0):
                pass
            elif(len(_set)>1):
                xorSum+=functools.reduce(lambda x, y: x^y,_set )
            else:
                xorSum+=_set[0]
            if (xorSum>stopRange):
                break
    print(xorSum%stopRange)

#solution based on http://math.stackexchange.com/questions/712487/finding-xor-of-all-subsets/712500#712500 
#
def fastSolution():
    for _ in range(int(input())):
        input()
        inputSet= list(map(int, input().split()))
        print((functools.reduce(lambda x,y: x|y,inputSet )*(2**(len(inputSet)-1)))%stopRange)

        
fastSolution()