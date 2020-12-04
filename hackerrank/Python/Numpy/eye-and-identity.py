#https://www.hackerrank.com/challenges/np-eye-and-identity
import numpy
N,M= map(int,input().split())
print(numpy.eye(N,M, k = 0)) 