#https://www.hackerrank.com/challenges/np-sum-and-prod
import numpy
N,M= map(int,input().split())
arr = []
for _ in range(N):
    arr.append(list(map(int,input().split())))
arr=numpy.array(arr)
suma=numpy.sum(arr, axis = 0)
print(numpy.prod(suma, axis = 0))