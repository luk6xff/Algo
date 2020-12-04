#/********************************************/
#/********************Strings*****************/
#/********************************************/



#/********************************************/

#/**sWAP cASE*******/

#/********************************************/
data = input()
res = str()
for i in data:
    if i.islower():
         i=i.upper()
    else:
        i=i.lower()
    res+=i
print(res)



#/********************************************/

#/**String Split and Join*******/

#/********************************************/
a = input().split(" ")
print("-".join(a))


#/********************************************/

#/**Mutations*******/

#/********************************************/
a = input()
data = input().split(" ")
num = int(data[0])
char= data[1] 
a = a[:num] + char + a[num+1:]
print(a)



#/********************************************/

#/**List Comprehensions*******/

#/********************************************/
astr= input()
bsubstr= input()
count =0
beg=-1
for i in range(0, len(astr)):
    beg= astr.find(bsubstr,beg+1)
    if beg != -1:
        count+=1
    else:
        break
print(count)

#/********************************************/

#/**Find a string*******/

#/********************************************/
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

#/********************************************/

#/**String Validators*******/

#/********************************************/
#1st solution
S = input()
c=0
for x in S:
    if(x.isalnum()):
        print("True")
        break
    c=c+1
if(c==len(S)):
   print("False")
c=0
for x in S:
    if(x.isalpha()):
        print("True")
        break
    c=c+1
if(c==len(S)):
   print("False")
c=0
for x in S:
    if(x.isdigit()):
        print("True")
        break
    c=c+1
if(c==len(S)):
   print("False")
c=0
for x in S:
    if(x.islower()):
        print("True")
        break
    c=c+1
if(c==len(S)):
   print("False")
c=0
for x in S:
    if(x.isupper()):
        print("True")
        break
    c=c+1
if(c==len(S)):
   print("False")

#2nd solution
s=raw_input()
a=[False,False,False,False,False]
for x in s:
    if x.isalnum():
        a[0]=True
    if x.isalpha():
        a[1]=True
    if x.isdigit():
        a[2]=True
    if x.islower():
        a[3]=True
    if x.isupper():
        a[4]=True
for x in range(5):
    print a[x]



#/********************************************/

#/**The Minion Game*******/

#/********************************************/
def isVovel(letter):
    if (letter=='A' or letter=='E' or letter=='I' or letter=='O' or letter=='U'):
        return True
    return False

def countAllResult(word):
    sumK=0
    sumS=0
    for i in range(len(word)):
        if (isVovel(word[i])):
            sumK=sumK+len(word)-i
        else:
            sumS=sumS+len(word)-i
    if(sumS>sumK):
        print("Stuart "+str(sumS))
    elif(sumS<sumK):
        print("Kevin "+str(sumK))
    else:
        print("Draw")
      
word =input()
countAllResult(word)

#/********************************************/

#/**Text Alignment*******/

#/********************************************/

thickness = int(raw_input()) #This must be an odd number
c = 'H'

#Top Cone
for i in range(thickness):
    print (c*i).rjust(thickness-1)+c+(c*i).ljust(thickness-1)

#Top Pillars
for i in range(thickness+1):
    print (c*thickness).center(thickness*2)+(c*thickness).center(thickness*6)

#Middle Belt
for i in range((thickness+1)/2):
    print (c*thickness*5).center(thickness*6)    

#Bottom Pillars
for i in range(thickness+1):
    print (c*thickness).center(thickness*2)+(c*thickness).center(thickness*6)    

#Bottom Cone
for i in range(thickness):
    print ((c*(thickness-i-1)).rjust(thickness)+c+(c*(thickness-i-1)).ljust(thickness)).rjust(thickness*6)  


	
#/********************************************/

#/**Text Wrap*******/

#/********************************************/
import textwrap
S = str(input())
w= int(input())

wrappedTxt= textwrap.wrap(S,w)
print(textwrap.fill(S,w))



#/********************************************/

#/**Designer Door Mat*******/

#/********************************************/
N, M = map(int,input().split()) # More than 6 lines of code will result in 0 score. Blank lines are not counted.
for i in range(1,N,2): 
    print ((".|."*i).center(M,"-"))
print ("WELCOME".center(M,"-"))
for i in range(N-2,-1,-2): 
    print ((".|."*i).center(M,"-"))
	
	
	
	
#/********************************************/

#/**String Formatting*******/

#/********************************************/	
#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def solution():
    N = int(raw_input())
    if N<1 or N>99:
        return
    binLen=len((bin(N)[2:]))
    for i in range(1,N+1,1):
        print('%*d %*o %*X '%(binLen,i,binLen,i,binLen,i)+bin(i)[2:].rjust(binLen))


solution()
