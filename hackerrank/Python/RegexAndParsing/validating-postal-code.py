#https://www.hackerrank.com/challenges/validating-postalcode
import re
postalCode= input()
correctRange= re.match(r'^[1-9][0-9]{5}$',postalCode)
alternatingDigitPairs= re.search(r'(\d)(\d)\1\2', postalCode) #more than one alternating repetitive digits
print(not correctRange==None and alternatingDigitPairs==None)
    