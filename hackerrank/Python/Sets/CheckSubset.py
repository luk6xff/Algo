# /********************************************/
# /**Check Subset*******/
# /********************************************/ 
#!/usr/bin/python
#1st solution
for i in range(int(input())): 
    a = int(input()); A = set(input().split());b = int(input()); B = set(input().split())
    if(len(A.intersection(B))==a): print("True")#print(B==A.union(B))
    else: print("False")

#2nd solution

for i in range(int(input())): #More than 4 lines will result in 0 score. Do not leave a blank line also. 
    a = int(input()); A = set(input().split())
    b = int(input()); B = set(input().split())
    print(B==A.union(B))