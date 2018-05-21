# /********************************************/

# /**DefaultDict Tutorial*******/

# /********************************************/	
#!/usr/bin/python
import sys
from collections import defaultdict

if sys.version_info[0]>=3: raw_input=input

def solution():
    n,m = map(int,raw_input().split())
    d = defaultdict(list)
    if n<1 or m>10000 or m<1 or m>100 :
        return
    for i in range(1,n+1,1):
        key=str(input())
        if key in d:
            d[key].append(str(i))
        else: d[key]=[str(i)]
            
    for i in range(m):
        key=str(input())
        if key in d:
            print(' '.join(d[key]) )
        else: 
            print("-1")
        
        
    
solution()