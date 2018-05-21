#!/usr/bin/python
#https://www.hackerrank.com/challenges/validating-named-email-addresses
import email.utils
import re
for _ in range(int(input())):
    rawInput=input()
    mail=email.utils.parseaddr(rawInput)[1]
    if(re.findall(r'^[a-zA-Z]{1}\w+_*-*.*@[a-zA-Z]+\.[a-zA-Z]{1,3}$',mail,re.I)):
        print(rawInput)
