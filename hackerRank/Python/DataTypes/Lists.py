# /********************************************/

# /**Lists*******/

# /********************************************/

import sys
#print (sys.platform)
nrOfQueries = int(input())
myList= list()
for i in range(0,nrOfQueries):
    data= input().split() 
    if len(data)==3:
        if(data[0]=="insert"):
            myList.insert(int(data[1]),int(data[2]))
    elif len(data)==2:
        if(data[0]=="remove"):
            myList.remove(int(data[1]))
        elif(data[0]=="append"):
            myList.append(int(data[1]))
    elif len(data)==1:
        if(data[0]=="print"):
            print(myList)
        elif(data[0]=="sort"):
            myList.sort()
        elif(data[0]=="pop"):
            myList.pop()
        elif(data[0]=="reverse"):
            myList.reverse()

