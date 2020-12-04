#!/usr/bin/python

import sys
import re
if sys.version_info[0]<3: input =raw_input
data= input()
regex= r'(?<=[QWRTYPSDFGHJKLZXCVBNMqwrtypsdfghjklzxcvbnm])[AIEOUaeiou]{2,}(?=[QWRTYPSDFGHJKLZXCVBNMqwrtypsdfghjklzxcvbnm])'
m= re.findall(regex,data)
if not m:
    print("-1")
else:
    #print('\n'.join(m)) 
    #or
    for i in re.finditer(regex,data):
        print(i.group())
