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