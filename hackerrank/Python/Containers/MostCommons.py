##/********************************************/
# /**Most Commons*******/
# /********************************************/	
#!/usr/bin/python
import sys
from collections import Counter
from operator import itemgetter

if sys.version_info[0]<3: input=raw_input

def solution():
    dataStr = str(input())
    counterDict = Counter(dataStr.strip())      
    #mostCommonDict= sorted(counterDict.most_common(),key=itemgetter(0),reverse=True)
    #mostCommonDict=mostCommonDict[:3]
    #for key,value in mostCommonDict:
        #print(str(key)+" "+str(value))
    i=0
    for value,key in sorted((-value,key) for key,value in counterDict.most_common()):
        print(key+' '+str(-value))
        i+=1
        if i==3:
            break
solution()
