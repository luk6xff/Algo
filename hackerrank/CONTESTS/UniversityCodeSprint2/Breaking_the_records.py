#!/bin/python3
#https://www.hackerrank.com/contests/university-codesprint-2/challenges/breaking-best-and-worst-records
import sys


n = int(input().strip())
score = list(map(int, input().strip().split(' ')))

best_r = score[0]
best_r_count = 0
worst_r = score[0]
worst_r_count = 0
for val in score:
    if val > best_r:
        best_r = val
        best_r_count +=1
    if val < worst_r:
        worst_r = val
        worst_r_count +=1 
print(best_r_count, worst_r_count)
    