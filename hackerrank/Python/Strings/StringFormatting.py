#/********************************************/

#/**String Formatting*******/

#/********************************************/	
#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def solution():
    N = int(raw_input())
    if N<1 or N>99:
        return
    binLen=len((bin(N)[2:]))
    for i in range(1,N+1,1):
        print('%*d %*o %*X '%(binLen,i,binLen,i,binLen,i)+bin(i)[2:].rjust(binLen))


solution()