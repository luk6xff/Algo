# /********************************************/
# /*************Time Conversion****************/
# /********************************************/ 
#!/usr/bin/python

import sys
import cmath

if sys.version_info[0]<3: input =raw_input

def solution():
    hour= list(map(str, (input().split(":"))))
    if(len(hour) is not 3 ):
        return
    if(hour[2][2:]=="PM"):
        if int(hour[0]) != 12:
            hour[0]= str(int(hour[0])+12)
    elif int(hour[0])==12:
            hour[0]="00"       
    print(hour[0]+":"+hour[1]+":"+hour[2][:2])

solution()