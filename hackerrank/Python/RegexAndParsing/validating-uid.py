#https://www.hackerrank.com/challenges/validating-uid
#!/usr/bin/python
import re
for _ in range(int(input())):
    data =input()
    print("Valid" if(len(data)==10 and re.search(r'(.*[A-Z].*){2}',data) and re.search(r'(.*\d.*){3}',data) and re.search(r'[A-Za-z0-9]',data) and re.search(r'(\w).*\1{1,}',data) ==None ) else "Invalid")