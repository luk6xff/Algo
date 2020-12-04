#!/usr/bin/python
# /********************************************/
# /**Sort Data*******/
# /********************************************/	
import sys


if sys.version_info[0]<3: input =raw_input

def solution():
    N,M =map(int,input().split())
    data =list()
    for _ in range(N):
        data.append(list(map(int,input().split(" "))))
    K = int(input())
    sortedData= sorted(data, key=lambda _key: _key[K])
    for i in sortedData:
        print(" ".join(map(str,i)))
            

solution()