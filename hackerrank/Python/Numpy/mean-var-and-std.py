#https://www.hackerrank.com/challenges/np-mean-var-and-std
import numpy
N,M= map(int,input().split())
arr = []
for _ in range(N):
    arr.append(list(map(int,input().split())))
arr=numpy.array(arr)
print(numpy.mean(arr, axis = 1))
print(numpy.var(arr, axis = 0))
print(numpy.std(arr, axis = None))