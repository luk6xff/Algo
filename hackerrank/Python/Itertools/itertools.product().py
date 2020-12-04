# /********************************************/
# /**itertools.product()*******/
# /********************************************/	
#!/usr/bin/python
import sys
from itertools import product

if sys.version_info[0]<3: input =raw_input

def solution():
    A= map(int,input().split())
    B= map(int,input().split())
    prod= tuple(product(A,B))
    for i in range(len(prod)):
        print(prod[i],end=" ")    

solution()



#2nd
def solution2():
    A=list(map(int,input().split()))
    B=list(map(int,input().split()))
print(' '.join(str(e) for e in product(A,B)))   
