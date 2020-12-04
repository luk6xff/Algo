# /********************************************/
# /*************Library Fine****************/
# /********************************************/ 
#!/usr/bin/python
 
import sys
import cmath
 
if sys.version_info[0]<3: input =raw_input
 
def solution():
    actualDate= list(map(int, (input().split(" "))))
    expectedReturnDate= list(map(int, (input().split(" "))))
    if(expectedReturnDate[2] < actualDate[2] ):
        print(10000)
    elif expectedReturnDate[1] == actualDate[1] and expectedReturnDate[0] < actualDate[0] : #months equal
        print(15 *abs(actualDate[0]-expectedReturnDate[0]))
    elif expectedReturnDate[2] == actualDate[2] and expectedReturnDate[1] < actualDate[1]  :
        print(500 *abs(actualDate[1]-expectedReturnDate[1]))
    else:
        print(0)
 
solution()