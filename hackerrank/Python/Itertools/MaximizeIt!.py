# /********************************************/
# /**Maximize It!*******/
# /********************************************/	
#!/usr/bin/python
import sys
import itertools

if sys.version_info[0]<3: input =raw_input

def solution():
    K,M= map(int,input().split(' '))
    dataPowered= [[int(x)**2 for x in input().split(' ')[1:]]for _ in range(K)]
    print(max(sum(x)%M for x in itertools.product(*dataPowered)))
solution()