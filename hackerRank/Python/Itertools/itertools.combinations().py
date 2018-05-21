# /********************************************/
# /**itertools.combinations()*******/
# /********************************************/	
#!/usr/bin/python
import sys
from itertools import combinations

if sys.version_info[0]<3: input =raw_input

def solution():
    data= list(map(str,input().split()))
    for j in range(1,int(data[1])+1):
        print('\n'.join(''.join(i) for i in combinations(sorted(data[0]),j )))  

solution()
