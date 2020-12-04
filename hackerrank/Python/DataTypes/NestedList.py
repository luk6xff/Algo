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