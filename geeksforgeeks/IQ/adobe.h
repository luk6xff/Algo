//ADOBE


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
/*
    1) you are given the waste at certain positions with values between 1.01 and 3.00 and you can carry atmost 3.00kg at one time. You had to tell the minimum number of bags required to carry the waste.
    Input
    4
    1.30 1.40 1.50 1.60
    Output
    2
    Input
    4
    1.40 1.70 1.50 1.50
    Output
    3
*/
       
static void doAlgorithm(vector<double>& dataset){
	
    if(dataset.size()<1) return;
    
    
	
}

int main() {

    doAlgorithm(data);
	return 0;
}