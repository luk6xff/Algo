# /********************************************/

# /**Finding the percentage*******/

# /********************************************/

N=int(input())
myDict={}
for i in range(N):
    data= input().split(" ")
    list1=[data[1],data[2],data[3]]
    list1=list(map(float,list1));
    myDict[data[0]]=list1
name=input()
print("%0.2f" %(sum(myDict[name])/len(myDict[name])))