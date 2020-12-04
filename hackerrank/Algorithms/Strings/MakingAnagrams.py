#https://www.hackerrank.com/challenges/making-anagrams
a = input()
b = input()

aDict={}
bDict={}
result=0;
for i in range(ord('a'),ord('{')):   #'{' cuz in ascii it occurs after 'z'
    aDict[chr(i)]=0
    bDict[chr(i)]=0
for x in a:
    aDict[x]=aDict[x]+1
for x in b:
    bDict[x]=bDict[x]+1

for key,i in aDict.items():
    #if aDict[key] == bDict[key]:
    #    pass
    if aDict[key] > bDict[key]:
        result= result+(aDict[key]-bDict[key])
    elif aDict[key] < bDict[key]:
        result= result+(bDict[key]-aDict[key])
    #print(aDict[key])
print(result)