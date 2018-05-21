# /********************************************/
# /**Diagonal Difference*******/
# /********************************************/ 
#!/usr/bin/python

import sys

if sys.version_info[0]<3: input =raw_input

def solution():
    sum=0;
    sum2=0;
    N =int(input())
    matrix = [[0 for x in range(N)] for x in range(N)] 
    for i in range(N):
        matrix[i] = list(map(int,input().split()))
        
    for i in range(N):
        sum+=matrix[i][i]
    for i in range(N):
        sum2+=matrix[i][N-i-1] 
    print(abs(sum-sum2))

solution()