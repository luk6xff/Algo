#/********************************************/

#/**Capitalize!*******/

#/********************************************/
import re
data = input()
#1st way
#print(data)

#changedStr=''
#print(re.split('^W',data[0].upper()+data[1:]))
#for i in range(len(data)):
#    changedStr +=data[i][0].upper()+data[i][1:]+' '   
#print(changedStr)

#2nd way
print(*map(str.capitalize, data.split(' ')))