# /********************************************/
# /**The Captain's Room*******/
# /********************************************/ 
#!/usr/bin/python
import sys
from collections import Counter 
 
if sys.version_info[0]<3: input =raw_input

def solution():
    dummy= int(input())
    cnt= Counter(map(int, input().split()))
    print (cnt.most_common()[-1][0])
    
solution()




#2nd solution - with SETS, by DOSHI:
def solution():
    K = int(raw_input())

    roomList = map(int,raw_input().split())

    roomSet = set(roomList) 

    sumRoomSet = sum(roomSet) 
    sumRoomList = sum(roomList) 

    temp = sumRoomSet * K - sumRoomList 

    answer = temp / (K - 1) 

    print answer
solution()