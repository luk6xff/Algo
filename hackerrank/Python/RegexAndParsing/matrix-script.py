#https://www.hackerrank.com/challenges/matrix-script
import re
n,m = map(int, input().split())#row,column
encodedData= [None]*n*m
for row in range(n):
    data= input()
    for column in range(m):
        encodedData[row+column*n]=data[column]
#print(''.join(encodedData))
print(re.sub(r'(?<=\w)([^\w]+)(?=\w)'," ","".join(encodedData)))
#(?<=\w)/(?=\w) lookbehind/lookahead assertion to check whether any word character exists before/after special character