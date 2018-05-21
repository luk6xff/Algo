#https://www.hackerrank.com/challenges/np-array-mathematics
import numpy
N,M = map(int,input().split())
matrixN=[]
matrixM=[]
for _ in range(N):
    matrixN.append(list(map(int,input().split())))
for _ in range(N):
    matrixM.append(list(map(int,input().split())))
a = numpy.array(matrixN)
b = numpy.array(matrixM)
print(numpy.add(a, b))
print(numpy.subtract(a, b))      
print(numpy.multiply(a, b))      
#print(numpy.divide(a, b))
print(a//b)   
print(numpy.mod(a, b))          
print(numpy.power(a, b))
