# /********************************************/
# /**Utopina Tree*******/
# /********************************************/ 
#!/usr/bin/python
 
import sys
 
if sys.version_info[0]<3: input =raw_input
 
def solution():
    T =int(input())
    while T:
        height=1
        N =int(input())
        if(N==0):
            pass
        elif(N==1):
            height=2
        elif(not N%2):
            height= (2**(int(N/2)+1))-1
        else:
            height=(2**(int(N/2)+2))-2
        print(height)       
        T-=1
solution()