## Imports
import math
from collections import defaultdict
from collections import Counter
from collections import OrderedDict
from collections import deque
import operator
import re
import functools
import copy

## Variables
INF = float('inf')
NAN = float('nan')
BIG_NUM_POS = 10 ** 999
BIG_NUM_NEG = -10 ** 999

###############################################################################################
## Input helpers, data parsers etc
###############################################################################################
###############################################################################################
def input_from_file(day):
    "Open this day's input file."
    return open('inputs/input{}.txt'.format(day))

###############################################################################################
def test_from_file(day):
    "Open this day's test input file."
    return open('test{}.txt'.format(day))

###############################################################################################
def convert_to_matrix(input_data):
    "Converts input data to 2D matrix"
    if (isinstance(input_data, str)):
        input_data = input_data.splitlines()
    return [map_to_tuple(convert_input_value, line.split()) for line in input_data]

###############################################################################################
def convert_to_list(input_data):
    "Converts input data to list"
    if (isinstance(input_data, str)):
        input_data = input_data.split().replace('\n', '')
    return list(map(convert_input_value, input_data))

###############################################################################################
def convert_input_value(val):
    try:
        return int(val)
    except ValueError:
        try:
            fl = float(val)
            if math.isnan(fl) or math.isinf(fl):
                raise ValueError()
            return float(val)
        except ValueError:
            return val

###############################################################################################
## Iterable data helpers
###############################################################################################
def map_to_tuple(fn, *args):
    "Do a map and put the results into list"
    return tuple(map(fn, *args))

###############################################################################################



input_data = convert_to_list(input_from_file(10))
import re
P = []
for line in input_data:
    x,y,vx,vy = map(int, re.findall('-?\d+', line))
    P.append([x,y,vx,vy])



## solution
seconds = 0
for t in range(100000):
    min_x = min([x for x,y,_,_ in P])
    max_x = max([x for x,y,_,_ in P])
    min_y = min([y for x,y,_,_ in P])
    max_y = max([y for x,y,_,_ in P])
    W = 100
    if min_x+W >= max_x and min_y + W >= max_y:
        # print(t,min_x, max_x, min_y, max_y)
        for y in range(min_y, max_y+1):
            for x in range(min_x, max_x+1):
                if (x,y) in [(px,py) for px,py,_,_ in P]:
                    print('#', end='')
                else:
                    print('.', end ='')
            print()
    print(seconds)
    seconds += 1
    for p in P:
        p[0] += p[2]
        p[1] += p[3]

