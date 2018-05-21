#https://www.hackerrank.com/challenges/np-zeros-and-ones
import numpy
numbers= list(map(int,input().split()))
print(numpy.zeros(numbers, dtype = numpy.int))
print(numpy.ones(numbers, dtype = numpy.int))