#!/usr/bin/python
# /********************************************/
# /**Reduce Function
# https://www.hackerrank.com/challenges/reduce-function *******/
# /********************************************/	
from __future__ import print_function
from fractions import Fraction

if sys.version_info[0]<3: input =raw_input

def product(fracs):
    t = reduce(lambda x,y:x*y, fracs)
    return t.numerator, t.denominator
    
if __name__ == '__main__':
    fracs = []
    for _ in range(input()):
        fracs.append(Fraction(*map(int, input().split())))
    result = product(fracs)
    print(*result)
