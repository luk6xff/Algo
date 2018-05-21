//http://www.geeksforgeeks.org/minimum-steps-to-reach-a-destination/
/*

Given a number line from -infinity to +infinity. 
You start at 0 and can go either to the left or to the right. 
The condition is that in i’th move, you take i steps.

a) Find if you can reach a given number x
b) Find the most optimal way to reach a given number x, if we can indeed reach it. 
   For example, 3 can be reached om 2 steps, (0, 1) (1, 3)
   and 4 can be reached in 3 steps (0, -1), (-1, 1) (1, 4)
 
*/

///////////////////////////////////////////////1 version////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

void doAlgorithm(long long int x){
	
	int counter=0;
	int result=0;
	int diff=0;
	while(1){
		if(x==result)
			break;
		counter++;
		if(x>0)
			result+=counter;
		else
			result-=counter;
			
		if(abs(result)>abs(x)){
			diff= abs(result)-abs(x);
			int temp = counter-diff;
			while(counter>(temp)){
				cout<<result<<" "<<counter<<" "<<endl;
				if(x>0)
					result-=counter;
			 	else
			 		result+=counter;
				counter--;
			}
			if(x>0){
				result-=counter;
				result-=counter;
			}
			else{
				result+=counter;
				result+=counter;
			}
				
			
		}
	}
	cout<<"Nr of minimum steps to reach destination equals: "<<counter;
	
}


int main() {
    
    int x = 1000;
    
    doAlgorithm(x);
		
	return 0;
}