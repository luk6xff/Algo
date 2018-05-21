#!/usr/bin/python

import sys
import math
import re
if sys.version_info[0]<3: input =raw_input

m=re.search(r'([0-9a-zA-Z])\1{1,}',input())
if m:
    if m.group(1):
        print(m.group(1))
else:
    print('-1')    