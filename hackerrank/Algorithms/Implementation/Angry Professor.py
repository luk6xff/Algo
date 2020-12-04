# /********************************************/
# /**Angry Professor*******/
# /********************************************/
#!/usr/bin/python
 
import sys
 
if sys.version_info[0]<3: input =raw_input
 
def solution():
    T =int(input())
    while T:
        N,K= map(int,input().split())
        students= list(map(int,input().split()))
        sumBeforeClassStarted=0
        resp="YES"
        for x in students:
            if x <=0:
                sumBeforeClassStarted+=1
                if sumBeforeClassStarted>=K:
                resp="NO"
                break
        print(resp)
        T-=1
solution()
 