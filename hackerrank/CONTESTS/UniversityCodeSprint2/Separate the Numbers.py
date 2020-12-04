#!/bin/python3
#https://www.hackerrank.com/contests/university-codesprint-2/challenges/separate-the-numbers

import sys
import re

def find_num(num_str, prev_val):
    if num_str[0] == '0':      
        return 0
    for i, _ in enumerate(num_str):
        if prev_val == -1 and i+1 >= len(num_str):
            return 0
        sum_val = int(num_str[:i+1])
        if prev_val == -1 or sum_val == prev_val+1:
            if i+1 >= len(num_str) or (sum_val+1 == find_num(num_str[i+1:], sum_val)):
                return sum_val
        if prev_val >= 0  and sum_val > prev_val+1:
            return 0
    return 0
    
q = int(input().strip())
for a0 in range(q):
    s = input().strip()
    res = find_num(s, -1)
    print("YES %d"%res if res > 0 else "NO")
