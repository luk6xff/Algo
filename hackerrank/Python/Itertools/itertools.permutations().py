# /********************************************/
# /**itertools.permutations()*******/
# /********************************************/	
#!/usr/bin/python
import sys
from itertools import permutations

if sys.version_info[0]<3: input =raw_input

def solution():
    data= list(map(str,input().split()))
    print('\n'.join(''.join(i) for i in sorted(permutations(data[0],int(data[1]) ))))   

solution()