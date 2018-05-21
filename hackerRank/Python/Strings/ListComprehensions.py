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
