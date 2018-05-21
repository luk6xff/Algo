//MICROSOFT


//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>
#include <numeric>
#include <chrono>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef string STR;


#define V(x) vector<x>
#define P(a,b) pair<a,b>


#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))




template<typename TimeUnit> TimeUnit getTimeDuration(std::chrono::time_point<std::chrono::system_clock> start , std::chrono::time_point<std::chrono::system_clock> end ){
	std::chrono::duration<TimeUnit> diff = end-start;
	return diff.count();
}
/*
USAGE:
auto start = std::chrono::system_clock::now();
auto end = std::chrono::system_clock::now();
std::cout << "Time Expired =  "<< getTimeDuration<double>(start ,end);
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************************************************************************/
//TASK 1:
/*
//http://www.geeksforgeeks.org/print-a-pattern-without-using-any-loop/
Print a pattern without using any loop
Given a number n, print following pattern without using any loop.

Input: n = 16
Output: 16, 11, 6, 1, -4, 1, 6, 11, 16

Input: n = 10
Output: 10, 5, 0, 5, 10
*/


#include <iostream>
using namespace std;

void printPattern(int m , int num,bool upDownFlag){
	if(num>m)
		return;	
	cout<<num<<" ";

	if(num <=0||upDownFlag){
		printPattern(m,num+5,true);
	}
	else
		printPattern(m,num-5,false);
	
}

int main() {
	printPattern(16,16,false);
	return 0;
}



/*******************************************************************************************************************************************/
//TASK 2:
//MICROSOFT
//https://ideone.com/RJySQe
//http://www.geeksforgeeks.org/move-zeroes-end-array/
#include <iostream>
using namespace std;
//1st ver
void pushZerosToEnd1(int arr[], int n)
{
 int zeroCounter=0; //counts 0's occurences
	 for(int i =0;i<n;i++){
	 if(arr[i]==0)
		zeroCounter++;
	 else
		arr[i-zeroCounter]=arr[i];
	 }
	 while(zeroCounter--){
		arr[n-zeroCounter]=0; 
	 
	 }
}
 
//2nd ver
void pushZerosToEnd2(int arr[], int n)
{
	 int nonZeroCounter=0; //counts 0's occurences
	 for(int i =0;i<n;i++){
		 if(arr[i]!=0)
			arr[nonZeroCounter++]=arr[i];
	 }
	 while(nonZeroCounter<n){
		arr[nonZeroCounter++]=0; 
	 
	 }
}
// Driver program to test above function
int main()
{
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    pushZerosToEnd2(arr, n);
    cout << "Array after pushing all zeros to end of array :\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}







/*******************************************************************************************************************************************/


/*******************************************************************************************************************************************/
//TASK 2: