# /********************************************/

# /**Sets - Symmetric Difference*******/

# /********************************************/
def doAlgorithm(dataN,dataM):
    Mset =set(list(map(int,dataM)))
    Nset =set(list(map(int, dataN)))
    Ndiff = Mset.difference(Nset)
    Mdiff =Nset.difference(Mset) 
    diff =list(Ndiff)+list(Mdiff)
    diff.sort()
    for i in range(len(diff)):
        print(diff[i])



import sys
Mnum = int(input())
dataM= input().split(" ")
Nnum = int(input())
dataN= input().split(" ")
doAlgorithm(dataN,dataM)
    