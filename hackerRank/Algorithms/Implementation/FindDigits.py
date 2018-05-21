# /********************************************/
# /**Find Digits*******/
# /********************************************/ 
#!/usr/bin/python
 
import sys
 
if sys.version_info[0]<3: input =raw_input
 
def solution():
    T =int(input())
    while T:
        nrOfDividers=0
        N =int(input())
        Nstr=str(N)
        for c in Nstr:
            if(int(c)==0):
                pass
            elif (N%int(c))==0:
                nrOfDividers+=1
        T-=1
        print(nrOfDividers)
solution()

def solution2():
    T =int(input())
    while T:
        N=int(input())
        print(len([1 for i in str(N) if i !='0' and N%int(i)==0]))