//NHAY
//Kod zadania: NHAY - A Needle in the Haystack

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




static void doAlgorithm(string& substring,string& dataset){
	
    vector<int> posVec;
	auto pos = dataset.find( substring );
	if( pos == string::npos )
    {
        cout <<"\n";
        return;
    }
    else{
    	do{
    		posVec.push_back(pos);
    		pos = dataset.find( substring ,pos+1 );
    	}while(pos!=string::npos);
    }
    sort(posVec.begin(),posVec.end());
    for(auto data:posVec){
    	cout<<data<<"\n";
    }
}


int main() {
    int n;
    string substring,data;
    std::ios::sync_with_stdio(false);
	do{
	    if(!(cin>>n)) return 0;
	    cin.ignore();
		getline(cin,substring);
	    getline(cin,data);
		//cout<<substring<<" "<<data<<endl;
		doAlgorithm(substring, data);
	}while(1);
		
	return 0;
}