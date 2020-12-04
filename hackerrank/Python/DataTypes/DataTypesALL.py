# /********************************************/
# /******DataTypes*******/
# /******DataTypes*******/
# /******DataTypes*******/
# /********************************************/

# /********************************************/

# /**Lists*******/

# /********************************************/
# /*
# Task 
# You have to initialize your list L = [] and follow the N commands given in N lines.

# Commands will be 1 of the 8 commands as given above, other than extend, and each command will have its value separated by space.

# Follow this example:

# Sample Input

# 12
# insert 0 5
# insert 1 10
# insert 0 6
# print 
# remove 6
# append 9
# append 1
# sort 
# print
# pop
# reverse
# print
# Sample Output

# [6, 5, 10]
# [1, 5, 9, 10]
# [9, 5, 1]
# */
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



# /********************************************/

# /**Tuples*******/

# /********************************************/
import sys
nrOfNum = int(input())
data= input().split(" ")
tuple=()
for i in range(0,nrOfNum):
    tuple =tuple +(int(data[i]),)
print(hash(tuple))  


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
    
 

# /********************************************/

# /**List Comprehensions*******/

# /********************************************/
#1st solution
X=[x for x in range(int(input())+1)]
Y=[y for y in range(int(input())+1)]
Z=[z for z in range(int(input())+1)]
N=int(input())
comprehensionList= []
for x in X: 
    for y in Y:
        for z in Z:
            if (x+y+z) != N:
                comprehensionList.append([x,y,z]) 
comprehensionList.sort()
print(comprehensionList)


#2nd solution
X=int(input())
Y=int(input())
Z=int(input())
N=int(input())
comprehensionList= [[x,y,z] for x in range(X + 1) for y in range(Y + 1) for z in range(Z + 1) if x + y + z != N]
comprehensionList.sort()
print(comprehensionList)

# /********************************************/

# /**Find second largest number in a list*******/

# /********************************************/
dummy = int(input())
a=list(map(int, input().split(" ")))
maxNum=max(a)
count=0
for i in a:
    if i==maxNum:
        count+=1
for i in range(count):
    a.remove(maxNum)
print(max(a))




# /********************************************/

# /**Nested list*******/

# /********************************************/
#1st solution
N = int(input())
data =[]
for i in range(N):
    data.append([input(),float(input())])
sortSet=set()
for i in range(N):
    sortSet.add(data[i][1])
sortSet= list(sortSet)  
sortSet.sort()
nameList=[]
for i in range(N):
    if data[i][1]==sortSet[1]:
        nameList.append(data[i][0])
nameList.sort()
for i in nameList:
    print(i)


#2nd solution
inputData = [[input(),float(input())] for i in range(int(input()))]
markList=list(set([i[1] for i in inputData ]))
markList.sort()
secondLowestVal=markList[1]
data =list(filter(lambda x:x[1]==secondLowestVal,inputData ))
data.sort()
for i in data :
    print(i[0])