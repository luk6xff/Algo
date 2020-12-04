#!/usr/bin/python
#https://www.hackerrank.com/challenges/botcleanr


import math
# Head ends here
def next_move(posr, posc, board):
    valid_chars = ['b', '-', 'd'];
    coords = give_closest_dirty_cell(posr, posc, board)
    if coords == (-1, -1):
        print(" ")
    elif (posr, posc) == coords: # clean now
        print("CLEAN")
    elif posr == coords[0]: # same row
        if posc > coords[1]:
            print("LEFT")
        else:
            print("RIGHT")            
    elif posc == coords[1]: # same col
        if posr < coords[0]:
            print("DOWN")
        else:
            print("UP")    
    else: # all different, first go through rows
        if posc > coords[1]:
            print("LEFT")
        else:
            print("RIGHT")
            
def give_closest_dirty_cell(row_num, col_num, board):
    # search for dirty in all rows
    min_distance = 999999999999999 # min dist between 2 coordinates
    min_coordinates = (-1, -1)
    for row_idx in range(len(board)):
        for col_idx in range(len(board[0])):
            if board[row_idx][col_idx] == 'd':
                coordinates = (row_idx, col_idx)
                dist = math.sqrt(pow(row_idx - row_num,2) + pow(col_idx - col_num,2))
                if min_distance > dist:
                    min_coordinates = coordinates
                    min_distance = dist
    return min_coordinates

# Tail starts here
if __name__ == "__main__":
    pos = [int(i) for i in input().strip().split()]
    board = [[j for j in input().strip()] for i in range(5)]
    next_move(pos[0], pos[1], board)
