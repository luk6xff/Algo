#!/usr/bin/python

import sys
import math
import re
if sys.version_info[0]<3: input =raw_input

S= input()
k= input()
m= re.findall(k,S)
if not m:
    print("(-1, -1)")
else:
    for m in re.finditer(r'(?=(%s))'%(k),S):
        print((m.start(1),m.end(1)-1))