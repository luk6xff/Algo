#!/usr/bin/python
# /********************************************/
# /**Re.split()*******/
# /********************************************/	
import sys
import math
import re
if sys.version_info[0]<3: input =raw_input


print('\n'.join([x for x in re.split('[\,]|[\.]*',input()) if x is not '']))