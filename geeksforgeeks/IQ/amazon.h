//AMAZON


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
/*TASK 1:
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.

Examples:
a) For any array, rightmost element always has next greater element as -1.
b) For an array which is sorted in decreasing order, all elements have next greater element as -1.
c) For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.

Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1
d) For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.

  Element        NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12     -->     -1
*/
       
static void doAlgorithm(vector<int>& dataset){
	
    if(dataset.size()<1) return;
    
    vector<int> temp;
    
    temp.push_back(dataset[0]);
    
    for(int i=1; i<dataset.size();i++){
    	
    	int x= dataset.at(i);
    	
    	int end= temp.size();
    	while(end){
    		
    		if(x>temp.at(end-1)){
    			cout<<temp.at(end-1)<<"   ---->    "<<x<<endl;
    			temp.erase(temp.begin()+end-1);
    		}
    		end--;
    	}
    	temp.push_back(dataset[i]);

    }
    
    for(auto elem: temp){
    	cout<<elem<<" "<<"   ---->    "<<-1<<endl;
    }
}

int main() {
	vector<int> data ={4, 5, 2, 25};
    doAlgorithm(data);
	return 0;
}


/*******************************************************************************************************************************************/