# /********************************************/
# /**Set.symmetric_difference()Operation*******/
# /********************************************/	
#!/usr/bin/python
import sys


if sys.version_info[0]<3: input =raw_input

def solution():
    n = int(input())
    sEng = set(map(int, input().split()))
    n = int(input())
    sFra = set(map(int, input().split()))
    print (len(sEng.symmetric_difference(sFra)))

solution()