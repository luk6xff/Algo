#/********************************************/

#/**Mutations*******/

#/********************************************/
a = input()
data = input().split(" ")
num = int(data[0])
char= data[1] 
a = a[:num] + char + a[num+1:]
print(a)

