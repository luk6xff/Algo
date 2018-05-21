#https://www.hackerrank.com/challenges/np-dot-and-cross
import numpy
N = int(input().strip())
matrix1=[]
matrix2=[]
for _ in range(N):
    matrix1.append(list(map(int,input().split())))
for _ in range(N):
    matrix2.append(list(map(int,input().split())))
matrix1 = numpy.array(matrix1)
matrix2 = numpy.array(matrix2)
print(numpy.dot(matrix1, matrix2))