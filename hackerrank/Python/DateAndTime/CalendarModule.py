# /********************************************/
# /**Calendar Module*******/
# /********************************************/	
#!/usr/bin/python
import sys
import calendar

if sys.version_info[0]<3: input =raw_input

def solution():
    dataTime= list(map(int,input().split()))
    print(calendar.day_name[calendar.weekday(dataTime[2], dataTime[0],dataTime[1])].upper())
solution()