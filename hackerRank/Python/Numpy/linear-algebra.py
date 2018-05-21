#https://www.hackerrank.com/challenges/np-linear-algebra
import numpy as np
N = int(input().strip())
A=[]
for _ in range(N):
    A.append(list(map(float,input().split())))
print(np.linalg.det(np.array(A)))