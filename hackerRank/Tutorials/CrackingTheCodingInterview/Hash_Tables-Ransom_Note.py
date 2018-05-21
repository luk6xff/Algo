#https://www.hackerrank.com/challenges/ctci-ransom-note
from collections import Counter
def ransom_note(magazine, ransom):
    cnt = Counter()
    for word in magazine:
        cnt[word] += 1
    for word in ransom:
        if cnt[word] == 0 :
            return False
        cnt[word] -= 1
    return True            
    

m, n = map(int, input().strip().split(' '))
magazine = input().strip().split(' ')
ransom = input().strip().split(' ')
answer = ransom_note(magazine, ransom)
if(answer):
    print("Yes")
else:
    print("No")
    
