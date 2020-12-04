#https://www.hackerrank.com/challenges/connected-cell-in-a-grid
def getBiggestRegion(grid):
    maxRegion = 0
    for x in range(len(grid)):
        for y in range(len(grid[0])):
            maxRegion = max(maxRegion, dfs(x, y))
    return maxRegion
    

grid = []
n = int(input().strip())
m = int(input().strip())

neighbour = [(-1,0), (1,0), (1,1), (-1,-1), (-1, 1), (0,-1), (0,1), (1,-1)]

def dfs(x, y):
    if(grid[x][y] == 1):
        grid[x][y] = 0
        region = 1
        for neigh in neighbour:
            if 0 <= x+neigh[0] < n and 0 <= y+neigh[1] < m:
                region += dfs(x+neigh[0], y+neigh[1])     
    else:
        region = 0
    return region
        
    
for grid_i in range(n):
    grid_t = list(map(int, input().strip().split(' ')))
    grid.append(grid_t)
        
print(getBiggestRegion(grid))
