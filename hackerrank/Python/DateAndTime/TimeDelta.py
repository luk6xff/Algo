# /********************************************/
# /**Time Delta*******/
# /********************************************/	
#!/usr/bin/python
import sys
import datetime

if sys.version_info[0]<3: input =raw_input

def solution():
    for __ in range(int(input())):
        t1=input()
        t2=input()
        dt1 = datetime.datetime.strptime(t1, "%a %d %b %Y %H:%M:%S %z")
        dt2 = datetime.datetime.strptime(t2, "%a %d %b %Y %H:%M:%S %z")
        print(int(abs(dt1-dt2).total_seconds()))
solution()