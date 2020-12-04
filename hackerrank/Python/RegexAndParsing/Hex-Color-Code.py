#!/usr/bin/python
import re

inCssPattern= False
for _ in range(int(input())):
    line = input().strip()
    if len(line) and line[-1]=='{':
        inCssPattern= True
    elif len(line) and line[-1]=='}':
        inCssPattern= False
    elif inCssPattern:
        for match in re.finditer(r'(#([0-9a-fA-F]{3}){1,2})',line):
            print(match.group(0).strip())