#/********************************************/
#/**Taum and B'day*******/
#/********************************************/ 
#!/bin/python3

import sys
if sys.version_info[0]<3: input =raw_input

t = int(input().strip())
for a0 in range(t):
    b,w = input().strip().split(' ')
    b,w = [int(b),int(w)]
    x,y,z = input().strip().split(' ')
    x,y,z = [int(x),int(y),int(z)]
    costB=b*x
    costW=w*y
    if(costB>(y*b+z*b)):
        costB=(y*b+z*b)
    if(costW>(x*w+z*w)):
        costW=(x*w+z*w)
    print(str(costB+costW))