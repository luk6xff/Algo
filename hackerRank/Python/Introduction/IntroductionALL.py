# /********************************************/
# /**Introduction*******/
# /**Introduction*******/
# /**Introduction*******/
# /********************************************/
# /********************************************/

# /**Hello World!*******/

# /********************************************/
print "Hello World!" 


# /********************************************/

# /**Raw Input*******/

# /********************************************/
print(raw_input())


# /********************************************/

# /**Arithmetic Operators*******/

# /********************************************/
a = int(raw_input())
b = int(raw_input())
print(a+b)
print(a-b)
print(a*b)
 

# /********************************************/

# /**Python: Division*******/

# /********************************************/
from __future__ import division
a= int(raw_input())
b= int(raw_input())
print(a//b)
print(a/b)




# /********************************************/

# /**Mod Divmod*******/

# /********************************************/
from __future__ import division
a =int(raw_input())
b =int(raw_input())
print(a//b)
print(a%b)
print(divmod(a,b))



# /********************************************/

# /**Power - Mod Power*******/

# /********************************************/
a =int(raw_input())
b =int(raw_input())
m =int(raw_input())
print(a**b)
print(pow(a,b,m))


# /********************************************/

# /**Integers Come In All Sizes*******/

# /********************************************/
a= int(raw_input())
b= int(raw_input())
c= int(raw_input())
d= int(raw_input())
print(a**b+c**d)

# /********************************************/

# /**Loops*******/

# /********************************************/
N= int(raw_input())
for i in range(N):
    print(i*i)

	
	
# /********************************************/

# /**What's Your Name?*******/

# /********************************************/
name= str(raw_input())+" "
name+= str(raw_input())
print("Hello "+name+"! You just delved into python.")




# /********************************************/

# /**Triangle Quest*******/

# /********************************************/
for i in range(1,int(input())): 
    print( int(i*(10**i - 1) / 9) )
	
	
# /********************************************/

# /**Interchange two numbers*******/

# /********************************************/
a= (int(raw_input()),int(raw_input()))
print(a[-1])
print(a[0])




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