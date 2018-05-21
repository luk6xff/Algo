#!/usr/bin/python
# /********************************************/
# /**Dealing with Complex Numbers*******/
# /********************************************/	
import sys
import math

if sys.version_info[0]<3: input =raw_input

class Complex():
    
    def __init__(self, re=0, im=0):
        self.re =re
        self.im =im
    
    def __add__(self, other):
        newObj= Complex()
        newObj.re =self.re+ other.re
        newObj.im =self.im+ other.im
        return newObj
    
    def __sub__(self, other):
        newObj= Complex()
        newObj.re =self.re- other.re
        newObj.im =self.im- other.im
        return newObj
    
    def __mul__(self, other):
        newObj= Complex()
        newObj.re =self.re* other.re -(self.im* other.im) 
        newObj.im =self.re* other.im +self.im*other.re
        return newObj

    def __floordiv__(self, other):
        temp= Complex(other.re,-other.im)
        newObj= self*temp
        temp2= other*temp
        newObj.re= newObj.re/temp2.re
        newObj.im= newObj.im/temp2.re
        return newObj    

    def mod(self):
        strReal= math.sqrt(self.re**2+ self.im**2)
        return Complex(strReal,0)    
    
    def __str__(self):
        retStr=str("%.2f"%self.re)
        if(self.im <0):
            retStr+=str("%.2f"%self.im)
        else:
            retStr+='+'+str("%.2f"%self.im)
        retStr+="i"
        return retStr

def solution():
    c = Complex(*map(float,input().split(' ')))
    d = Complex(*map(float,input().split(' ')))
    print(str(c+d))
    print(str(c-d))
    print(str(c*d))
    print(str(c//d))
    print(str(c.mod()))
    print(str(d.mod()))
solution()