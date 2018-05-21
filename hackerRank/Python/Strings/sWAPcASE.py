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

