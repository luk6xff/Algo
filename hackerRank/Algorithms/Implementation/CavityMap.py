# /********************************************/
# /**Cavity Map*******/
# /********************************************/ 
#!/usr/bin/python
 
import sys
 
if sys.version_info[0]<3: input =raw_input

def findCavities(grid):
    if grid is None:
        return None
    rows= len(grid)
    cols= len(grid[0])
    idxArray = list()
    for i in range(1,rows-1):
        for j in range(1,cols-1):
            try:
                if grid[i-1][j]<grid[i][j] and grid[i+1][j]<grid[i][j] and grid[i][j-1]<grid[i][j] and  grid[i][j+1]<grid[i][j]:
                    idxArray.append(str(i)+" "+str(j))  
            except(IndexError):
                pass
    return idxArray
def solution():
    n = int(input().strip())
    grid = []
    i = 0
    for i in range(n):
        gridT = str(input().strip())
        grid.append(gridT)
    idxList = findCavities(grid)
    if idxList is None:
        return
    #print(str((grid)))
    #print(str(findCavities(grid)))
    #for i in range(len(idxList)):
        #grid[int(idxList[i][0])][int(idxList[i][1])]='X'  #immutable object - not works
        #print(idxList[i].split(" "))
       
    finalGrid=[]
    for i in range(len(grid)):
        s =str()
        for j in range(len(grid[0])):
            occurenceFlag=0
            for k in range(len(idxList)):              
                if(i == int(idxList[k].split(" ")[0]) and j==int(idxList[k].split(" ")[1])):
                    s+='X'
                    occurenceFlag=1
            if occurenceFlag!=1:
                s+=grid[i][j]
        finalGrid.append(s)
    for i in range(len(finalGrid)):
        print(finalGrid[i])
    
solution()