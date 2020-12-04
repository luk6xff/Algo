# /********************************************/
# /**Compress the String!*******/
# /********************************************/	
#!/usr/bin/python
import sys
from itertools import groupby

if sys.version_info[0]<3: input =raw_input

def solution():
    dataStr= input()
    #print([k for k, g in groupby('AAAABBBCCDAABBB')] )
    #print([list(g) for k, g in groupby('AAAABBBCCDAABBB')] )
    print(' '.join('('+str(len(list(g)))+', '+str(k)+')' for k, g in groupby(dataStr)) )
solution()
