//http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
 
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
 
 //dynamic programming solution solution
static void doAlgorithm(vector<int>& dataset){
	
	if(dataset.size()<1)
		return;
	
	int maxSum= dataset[0];
	int tempSum= dataset[0];
	
	for(int i=1; i<dataset.size();i++){
		
		tempSum=max(dataset[i],tempSum+dataset[i]);
		maxSum= max(tempSum,maxSum);
		
		
	}
	cout<<"Maximum contiguous sum is: "<<maxSum<<endl;
}
 
 
int main() {
 vector<int> testData1 = {-2, -3, 4, -1, -2, 1, 5, -3};
 vector<int> testData2 = {-2, 1,3};
 
 doAlgorithm(testData1 );
 doAlgorithm(testData2 );
 
 return 0;
}
