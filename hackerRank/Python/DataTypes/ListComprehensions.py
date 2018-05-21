# /********************************************/

# /**List Comprehensions*******/

# /********************************************/
#1st solution
X=[x for x in range(int(input())+1)]
Y=[y for y in range(int(input())+1)]
Z=[z for z in range(int(input())+1)]
N=int(input())
comprehensionList= []
for x in X: 
    for y in Y:
        for z in Z:
            if (x+y+z) != N:
                comprehensionList.append([x,y,z]) 
comprehensionList.sort()
print(comprehensionList)


#2nd solution
X=int(input())
Y=int(input())
Z=int(input())
N=int(input())
comprehensionList= [[x,y,z] for x in range(X + 1) for y in range(Y + 1) for z in range(Z + 1) if x + y + z != N]
comprehensionList.sort()
print(comprehensionList)