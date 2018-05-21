#https://www.hackerrank.com/challenges/count-luck

neighbour = [(-1,0), (1,0), (1,1), (-1,-1), (-1, 1), (0,-1), (0,1), (1,-1)]


def dfs(x, y, grid):
    neighNumber = 0
    k = 0
    n = len(grid)
    m = len(grid[0])
    if(grid[x][y] == '.' or grid[x][y] == 'M'):
        grid[x][y] = '0' #visited
        neighNumber = 1
        for neigh in neighbour:
            if 0 <= x+neigh[0] < n and 0 <= y+neigh[1] < m:
                neighNumber += dfs(x+neigh[0], y+neigh[1], grid)
        if(neighNumber == 2):
                
    else:
        neighNumber = 0
    return neighNumber, 0



def solution():
    for _ in range(int(input())):
        N, M = map(int, input().split(" "))
        grid = []
        for _ in range(N):
            grid_row = list(map(str, input().strip()))
            grid.append(grid_row)
        K = int(input())
        print(grid)

        startingCell = (0,0)
        portingKey = (0,0)
        for n in range(N):
            for m in range(M):
                print("TEST: %d"%n)
                print("TEST: %d"%m)
                print("TEST_GRID: %s"%grid[n][m])
                if grid[n][m] == 'M':
                    startingCell = (n,m)    
                elif grid[n][m] == '*':
                    portingKey = (n,m)
        print("RESULT:")
        print(dfs(startingCell[0], startingCell[1], grid))

solution()
    
 
