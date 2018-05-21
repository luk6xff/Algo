//4797. skracanie identyfikatorow
//Kod zadania: WI_IDEN
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


static inline bool isDigit(char c){
	
	return c>='0'&&c<='9'?true:false;
}

static inline bool isLetter(char c){
	
	return (c>='a'&&c<='z'||c>='A'&&c<='Z')?true:false;
}

static inline bool isSpecialChar(char c){
	
	return (c=='$'||c=='_')?true:false;
}

static inline bool isVowel(char c){
	return (c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')?true:false;
}

static inline bool checkIfDone(int n, const STR& str){
	if(n>=str.length()){
   		cout<<str<<endl; 
   		return true;
	}
   	return false;
}


static void doAlgorithm(int n, STR& dataset){
	int length= dataset.length();
   if(length<1||length>65636) return;
   for(auto c:dataset){
   	
   		if(!(isSpecialChar(c)||isDigit(c)||isLetter(c)))
   			return;
   }
   if(checkIfDone(n, dataset)){
   		return;
   }
   
   for(auto it = dataset.end();it!=dataset.begin();--it){
   	
   	  if(isSpecialChar(*it)){
   	  		dataset.erase(it);
   	  		it++;
   	  }
   	  if(checkIfDone(n, dataset)){
   		return;
   	  }
   }
   
   
   for(auto it = dataset.end();it!=dataset.begin();--it){
   	
   	  if(isDigit(*it)){
   	  		dataset.erase(it);
   	  		it++;
   	  }
   	  if(checkIfDone(n, dataset)){
   		return;
   	  }
   }
   cout<<dataset<<endl;
   int count=0;
   for(auto it = dataset.begin();it!=dataset.end();++it){
   	  
   	  if(isVowel(*it)){
   	  	if(count>0){
   	  		dataset.erase(it);
   	  		it--;
   	  	}
   	  	count++;
   	  }
   	  if(checkIfDone(n, dataset)){
   	  	return;
   	  }
   }
   
   for(auto it = dataset.end()-1;it!=dataset.begin();--it){
   	  dataset.erase(it);
   	  it++;
   	  if(checkIfDone(n, dataset)){
   	  	return;
   	  }
   }
}


int main() {
    int n; 
    std::ios::sync_with_stdio(false);
    cin>>n;
	if(n> 65535||n<1)return 0;
	STR data;
	cin.ignore();
	getline(cin,data);
	doAlgorithm(n,data);
		
	return 0;
}




/*for C++ GCC5.1 */
    
/*
//4797. skracanie identyfikatorow
//Kod zadania: WI_IDEN
#include <iostream>
#include <string>


using namespace std;

typedef long long LL;
typedef long double LD;
typedef string STR;


static inline bool isDigit(char c){
	
	return c>='0'&&c<='9'?true:false;
}

static inline bool isLetter(char c){
	
	return (c>='a'&&c<='z'||c>='A'&&c<='Z')?true:false;
}

static inline bool isSpecialChar(char c){
	
	return (c=='$'||c=='_')?true:false;
}

static inline bool isVowel(char c){
	return (c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')?true:false;
}

static inline bool checkIfDone(int n, const STR& str){
	if(n>=str.length()){
   		cout<<str<<endl; 
   		return true;
	}
   	return false;
}


static void doAlgorithm(int n, STR& dataset){
	int length= dataset.length();
   if(length<1||length>65636) return;
   for(int i=0;i<dataset.length(); i++){
   	
   		if(!(isSpecialChar(dataset.at(i))||isDigit(dataset.at(i))||isLetter(dataset.at(i))))
   			return;
   }
   if(checkIfDone(n, dataset)){
   		return;
   }
   
   for(string::iterator it = dataset.end();it!=dataset.begin();--it){
   	
   	  if(isSpecialChar(*it)){
   	  		dataset.erase(it);
   	  		it++;
   	  }
   	  if(checkIfDone(n, dataset)){
   		return;
   	  }
   }
   
   
   for(string::iterator it = dataset.end();it!=dataset.begin();--it){
   	
   	  if(isDigit(*it)){
   	  		dataset.erase(it);
   	  		it++;
   	  }
   	  if(checkIfDone(n, dataset)){
   		return;
   	  }
   }
   //cout<<dataset<<endl;
   int count=0;
   for(string::iterator it = dataset.begin();it!=dataset.end();++it){
   	  
   	  if(isVowel(*it)){
   	  	if(count>0){
   	  		dataset.erase(it);
   	  		it--;
   	  	}
   	  	count++;
   	  }
   	  if(checkIfDone(n, dataset)){
   	  	return;
   	  }
   }
   
   for(string::iterator it = dataset.end()-1;it!=dataset.begin();--it){
   	  dataset.erase(it);
   	  it++;
   	  if(checkIfDone(n, dataset)){
   	  	return;
   	  }
   }
}


int main() {
    int n; 
    std::ios::sync_with_stdio(false);
    cin>>n;
	if(n> 65535||n<1)return 0;
	STR data;
	cin.ignore();
	getline(cin,data);
	doAlgorithm(n,data);
		
	return 0;
}



*/