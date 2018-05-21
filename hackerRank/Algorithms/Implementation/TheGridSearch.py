# /********************************************/
# /**The Grid Search*******/
# /********************************************/ 
#!/usr/bin/python
 
import sys
import math
if sys.version_info[0]<3: input =raw_input
 
 
 
def solution():
    T=int(input())
    for i in range(T):
        nrOfPatternRows = 0
        resp= "NO"
        R,C=map(int,input().split())
        matrix=list()
        pattern=[]
        for j in range(R):
            matrix.append(input())
        R,C=map(int,input().split())
        for j in range(R):
            pattern.append(input())
        #print(matrix)
        #print(pattern)
        for k in range(len(matrix)):
            idx= matrix[k].find(pattern[0])
            if (idx!=-1):
                for l in range(1,R):
                    resp= "YES"
                    if(l>=len(matrix)):
                        resp ="NO"
                        break;
                    if(matrix[k+l].find(pattern[l],idx,idx+C)==-1): 
                        #print(" NOT FOUND: " + matrix[k+l]+" " + pattern[l]+" " + " "+str(idx)+" " +str(C))
                        resp ="NO"
                        break  
                if(resp=="YES"):
                    break
        print(resp)
                
 
solution()