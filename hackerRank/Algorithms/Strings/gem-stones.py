#https://www.hackerrank.com/challenges/gem-stones
dictVal = {}
N = int(input())
for idx in range(N):
    charSet = set(input())
    for ch in charSet:
        if ch in dictVal:
            dictVal[ch] = dictVal[ch]+1; 
        else:
            dictVal[ch] = 1
print(len([x for x in dictVal.values() if x == N]))
    
    
