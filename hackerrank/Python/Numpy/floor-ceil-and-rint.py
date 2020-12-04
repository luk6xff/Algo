#https://www.hackerrank.com/challenges/floor-ceil-and-rint
import numpy
arr = numpy.array([float(num) for num in input().split()])
for method in ['floor','ceil','rint']:
	print(getattr(numpy,method)(arr))