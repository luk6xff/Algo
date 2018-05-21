# /********************************************/
# /**itertools.combinations_with_replacement()*******/
# /********************************************/	
#!/usr/bin/python
import sys
from itertools import combinations_with_replacement

if sys.version_info[0]<3: input =raw_input

def solution():
    data= list(map(str,input().split()))
    print('\n'.join(''.join(i) for i in combinations_with_replacement(sorted(data[0]),int(data[1]) )))  

solution()