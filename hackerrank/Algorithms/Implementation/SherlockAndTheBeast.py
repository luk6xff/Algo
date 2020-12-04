# /********************************************/
# /**Sherlock and The Beast*******/
# /********************************************/ 
#!/usr/bin/python
 
import sys
 
if sys.version_info[0]<3: input =raw_input
 
def solution():
    T =int(input())
    while T:
        N =int(input())
        i=N
        count5=0
        count3=0
 
        if(N<3):
            print("-1")
        else:
            while(i>-1):
                if(not i%3 and not((N-i)%5)):
                    count5=i
                    count3=N-i
                    break;
                i-=1
            if(count5==0 and count3==0):
                print("-1")
            else:
                print("5"*count5+"3"*count3)
        T-=1
solution()