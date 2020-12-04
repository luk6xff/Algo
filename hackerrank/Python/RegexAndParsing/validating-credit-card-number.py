#https://www.hackerrank.com/challenges/validating-credit-card-number
import re
for _ in range(int(input())):
    num = input()
    numberCard = re.search(r'^[4-6]{1}\d{3}([\ \-]?)(\d{4}\1\d{4}\1\d{4})$',num)
    #print(re.search(r'(\d)\1{3}',''.join(num.split('-'))))
    print("Valid" if(numberCard and not re.search(r'(\d)\1{3}',''.join(num.split('-')))) else "Invalid")