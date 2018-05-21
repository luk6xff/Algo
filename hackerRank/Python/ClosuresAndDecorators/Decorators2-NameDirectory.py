#https://www.hackerrank.com/challenges/decorators-2-name-directory
import sys
if sys.version_info[0]<3: input =raw_input
    
def sortPersonsByAge(func):
    def inner(persons):
        persons= sorted(persons, key= lambda x:x[2])
        return [func(data[0]+" "+data[1], "Mr." if data[3]=='M' else "Ms.") for data in persons]
    return inner

@sortPersonsByAge        
def printPersons(fullname, sex):
    return sex+" "+fullname
    
    
if __name__ == '__main__':
    persons =[]
    for _ in range(int(input())):
        personsData= input().split()
        #[firstname,surname,age, sex]
        persons.append([personsData[0],personsData[1],int(personsData[2]), personsData[3]])
    print('\n'.join(printPersons(persons)))