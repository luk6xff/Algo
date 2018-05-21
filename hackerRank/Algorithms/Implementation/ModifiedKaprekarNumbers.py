#/********************************************/
#/**Modified Kaprekar Numbers*******/
#/********************************************/ 
#!/bin/python3

import sys
def solution():
    p=int(input()) #nrOfStones
    q=int(input())
    occured= False
    for i in range(p,q+1):
        square= i*i
        squareStr=str(square)
        if(len(squareStr)<2):
            if(i==1):
                print(i, end=" ")
        else:    
            firstPart=int(squareStr[0:int(len(squareStr)/2)])
            #print(firstPart)
            secondPart=int(squareStr[int(len(squareStr)/2):])
            #print(secondPart)
            if(firstPart+secondPart==i):
                print(i, end=" ")
                occured=True
    if occured==False:
        print("INVALID RANGE")
solution()                