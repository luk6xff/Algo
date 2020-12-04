#!/usr/bin/python
import re
for _ in range(int(input())):
    line= re.sub(r"((?<=\s{1})(&&){1}(?=\s{1}))", "and", input())
    print(re.sub(r"((?<=\s{1})(\|{1}\|{1}){1}(?=\s{1}))", "or", line))
