#https://www.hackerrank.com/challenges/np-transpose-and-flatten
import numpy
N,M = map(int,input().split())
matrix=[]
for _ in range(N):
    matrix.append(list(map(int,input().split())))
matrix = numpy.array(matrix)
print(numpy.transpose(matrix))
print(matrix.flatten())