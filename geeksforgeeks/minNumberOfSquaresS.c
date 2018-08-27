//http://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/
//https://ideone.com/LNX4Y3
/*

A number can always be represented as a sum of squares of other numbers. Note that 1 is a square and we can always break a number as (1*1 + 1*1 + 1*1 + …). Given a number n, find the minimum number of squares that sum to X.

Examples:

Input:  n = 100
Output: 1
100 can be written as 102. Note that 100 can also be 
written as 52 + 52 + 52 + 52, but this
representation requires 4 squares.

Input:  n = 6
Output: 3
 
*/

///////////////////////////////////////////////1 version////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

static int getMinSquares(unsigned int n)
{
   if(n<2)
		return n;
   int tempSquare = sqrt(n);
   
   if((tempSquare*tempSquare) ==n){
	   
	   return 1;
   }
   int nrOfSquars =1;
   int sum = tempSquare*tempSquare;
   
   while(sum<n){
	   
	   tempSquare= sqrt(n-sum);
	   if(((tempSquare*tempSquare) ==(n-sum))){ 
		   nrOfSquars++;
		   break;
	   }
	   
	   sum+=(tempSquare*tempSquare);
	   nrOfSquars++;
	   
   }
   
   return(nrOfSquars);
}
///////////////////////////////////////////////2 dynamic programmming version//////////////////////////////////////////////////////
int getMinSquaresDP(unsigned int n)
{
    unsigned int *dp = new int[n+1];
 
    // getMinSquares table for base case entries
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
 
    // getMinSquares rest of the table using recursive
    // formula
    for (int i = 4; i <= n; i++)
    {
        // max value is i as i can always be represented
        // as 1*1 + 1*1 + ...
        dp[i] = i;
 
        // Go through all smaller numbers to
        // to recursively find minimum
        for (int x = 1; x <= i; x++) {
            int temp = x*x;
            if (temp > i)
                break;
            else dp[i] = min(dp[i], 1+dp[i-temp]);
        }
    }
 
    // Store result and free dp[]
    int res = dp[n];
    delete [] dp;
 
    return res;
}

static void testGetMinSquaresFunctionWithTime(void )
{
	auto start = std::chrono::system_clock::now();
	std::cout<<(getMinSquares(1000000)==1?"PASSED":"FAILED")<<endl; //10*10
	auto end = std::chrono::system_clock::now();
	std::cout << "Time Expired =  "<< getTimeDuration<double>(start ,end)<<endl;
	
	
	
	
	auto startDP = std::chrono::system_clock::now();
	std::cout<<(getMinSquaresDP(1000000)==1?"PASSED":"FAILED")<<endl; //10*10
	auto endDP = std::chrono::system_clock::now();
	std::cout << "Time Expired =  "<< getTimeDuration<double>(startDP ,endDP)<<endl;
	
	
}




static void testGetMinSquaresFunction(void )
{
	
	std::cout<<(getMinSquares(100)==1?"PASSED":"FAILED")<<endl; //10*10
	std::cout<<(getMinSquares(6)==3?"PASSED":"FAILED")<<endl; //2*2+1*1+1*1	
	std::cout<<(getMinSquares(999)==4?"PASSED":"FAILED")<<endl; //31*31+6*6+1*1+1*1	
}

int main()
{
	testGetMinSquaresFunction();
	testGetMinSquaresFunctionWithTime();
    return 0;
}


///////////////////////////////////////////////2 version////////////////////////////////////


