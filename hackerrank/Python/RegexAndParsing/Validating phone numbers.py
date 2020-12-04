#!/usr/bin/python
import re
for _ in range(int(input())):
    res= re.findall(r'(^[789]{1}[\d]{9}$)',input())
    if res:
        print("YES")
    else:
        print("NO")

