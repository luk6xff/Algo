# /********************************************/
# /**Input()*******/
# /********************************************/	
#!/usr/bin/python
import sys
if sys.version_info[0]<3: input =raw_input

def solution():
    x,y= map(int,input().split(' '))
    polynomial= eval(input())
    print(polynomial==y)
solution()
