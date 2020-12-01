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
    return open('inputs/test{}.txt'.format(day))
from collections import defaultdict


with test_from_file(13) as f:
#with input_from_file(13) as f:
    m = f.read().splitlines()
d = [[y for y in x] for x in m]
print(d)




## solution 1
from collections import defaultdict

state = defaultdict()
directs = {'<':(-1,0), '^':(0,1), 'v':(0,-1), '>':(1,0)}

num = 0
for x,v in enumerate(d):
    for y in range(len(v)):
        if v[y] in ('^', '<', '>', 'v'):
            state[num] = {'xy':(x,y), 's':v[y], 'd':0}
            num += 1
print(state)

while True:
    for k,v in state.items():
        if d[v['xy'][0]][v['xy'][1]] == '/':
            if v['s'] == '^':
                v['s'] = '>'
            elif v['s'] == 'v':
                v['s'] = '<'
            elif v['s'] == '<':
                v['s'] = 'v'
            elif v['s'] == '>':
                v['s'] = '^'
            v['xy'][0] += directs[v['s']][0]
            v['xy'][1] += directs[v['s']][1] 
        elif d[v['xy'][0]][v['xy'][1]] == '\\':
            if v['s'] == '^':
                v['s'] = '<'
            elif v['s'] == 'v':
                v['s'] = '>'
            elif v['s'] == '<':
                v['s'] = '^'
            elif v['s'] == '>':
                v['s'] = 'v'
            v['xy'][0] += directs[v['s']][0]
            v['xy'][1] += directs[v['s']][1]
        elif d[v['xy'][0]][v['xy'][1]] == '+':
            if v['d'] == 0: 
                v['xy'] += directs['<']
                v['xy'][0] += directs['<'][0]
                v['xy'][1] += directs['<'][1]
                v['s'] = '<'
            elif v['d'] == 2:  
                v['xy'] += directs['>']
                v['xy'][0] += directs['>'][0]
                v['xy'][1] += directs['>'][1]
                v['s'] = '>'
            elif v['d'] == 1:  
                v['xy'][0] += directs[v['s']][0]
                v['xy'][1] += directs[v['s']][1]                      
            v['d'] += 1
            v['d'] %= 3
        else:
            v['xy'][0] += directs[v['s']][0]
            v['xy'][1] += directs[v['s']][1]  
        #print(state)
    if state[0]['xy'] == state[1]['xy']:
        break
print(state[0]['xy'])
