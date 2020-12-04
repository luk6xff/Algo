#https://www.hackerrank.com/challenges/standardize-mobile-number-using-decorators
import sys
if sys.version_info[0]<3: input =raw_input
    
def formatMobileNumbers(func):
    def inner(numbers):
        numbers= sorted(numbers)
        for number in numbers:
            func(''.join(number)) 
    return inner

@formatMobileNumbers      
def printNumber(num):
    print("+91 "+num[-10:-5]+" "+num[-5:])
    
    
if __name__ == '__main__':
    numbers =[]
    for _ in range(int(input())):
        numbers.append(input()[-10:])
    printNumber(numbers)