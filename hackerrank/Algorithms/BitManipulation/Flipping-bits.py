#!/usr/bin/python
import binascii
import sys
T=int(input())

for _ in range(T):
    var =int(input())
    print(var^0xffffffff) #32bit