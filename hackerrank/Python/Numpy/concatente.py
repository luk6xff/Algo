#https://www.hackerrank.com/challenges/np-concatenate
import numpy
N,M,P = map(int,input().split())
matrixN=[]
matrixM=[]
for _ in range(N):
    matrixN.append(list(map(int,input().split())))
for _ in range(M):
    matrixM.append(list(map(int,input().split())))
matrixN = numpy.array(matrixN)
matrixM = numpy.array(matrixM)
print(numpy.concatenate((matrixN, matrixM), axis = 0))