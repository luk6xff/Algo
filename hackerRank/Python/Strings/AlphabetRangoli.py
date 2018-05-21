#/********************************************/

#/**Alphabet Rangoli*******/

#/********************************************/
import re
N = int(input())
width = N + N-1 +N-1+N-1
height= N+N-1
#print('a'+chr(ord('a')+N))
for i in range(height):
    data= []
    if(i <(int(height/2+1))):
        data= [chr(ord('a')+N-1-x) for x in range(i+1)]
    else: 
        data=[chr(ord('a')+N-1-x) for x in range(height-i)]
    data += data[::-1]
    data.remove(data[int(len(data)/2)])
    print('-'.join(data).center(width,'-'))