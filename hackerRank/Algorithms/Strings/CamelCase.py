#!/bin/python3
#https://www.hackerrank.com/challenges/camelcase
import sys
import re
print(len(re.findall(r'^[a-z]+|[A-Z]{1}[a-z]+', input().strip())))
