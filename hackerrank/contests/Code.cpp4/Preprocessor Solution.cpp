#include <limits>
#include <algorithm>    // std::max

#define INF std::numeric_limits<int>::max();
#define io(v) cin>>v
#define toStr(str) #str
#define FUNCTION(func,sign)  void func(int &m, int x){ m=  (((m) sign (x)) ? (m) : (x)); } 
#define foreach(v,i) for (int i=0;i<v.size();i++)


#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}

/*
Sample Input

5
32 332 -23 -154 65
Sample Output

Result = 486

*/