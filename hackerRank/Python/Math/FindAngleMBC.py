# /********************************************/
# /**Find Angle MBC*******/
# /********************************************/	
#!/usr/bin/python

  #A|
  # | \
  # |  \ 
  # |   \  
  # |  b|\- 1/2(AC) = z
  # |   | \
  # |  h|  \
  #B|r_ |_ a\C
  #  y     x

import sys
import math

if sys.version_info[0]<3: input =raw_input

def solution():
    AB= int(input())
    BC= int(input())
    AC=math.sqrt(AB*AB+BC*BC)
    z= 0.5*AC
    a= math.atan2(AB,BC)
    x= z* math.cos(a) 
    h= math.tan(a)*x
    y=BC-x
    r= math.degrees(math.atan(h/y) )    #result
    print(str(int(round(r)))+'°')


solution()