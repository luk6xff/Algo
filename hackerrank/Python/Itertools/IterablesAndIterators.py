# /********************************************/
# /**Iterables and Iterators*******/
# /********************************************/	
#!/usr/bin/python
import sys
import itertools

if sys.version_info[0]<3: input =raw_input

def solution():
    N= input()
    A=list(map(str,input().split()))
    K= int(input())
    nrOfLetters=0
    for x in itertools.combinations(A,K):
        if('a' in x):
            nrOfLetters+=1    
    print("%.3f"%(nrOfLetters/len(list(itertools.combinations(A,K)))))  
    

solution()