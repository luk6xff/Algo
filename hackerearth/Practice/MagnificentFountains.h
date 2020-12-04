#include <iostream>
#include <algorithm>    
#include <vector>       
using namespace std;
 
 
 
static bool compFunc (long long int i, long long int j) { return (i>j); }
 
static long long int gcd(long long int m, long long int n)
{
        long long int tmp;
        while(m) { tmp = m; m = n % m; n = tmp; }       
        return n;
}
 
static long long int lcm(long long int m, long long int n)
{
        return m / gcd(m, n) * n;
}
 
 
static void doAlgorithm(vector<long long int>& dataset){
	
	if(dataset.size()==0)
		return;
		
	sort(dataset.begin(),dataset.end(),compFunc);
 
	
	auto maxVal= *dataset.begin();
	auto tempMaxVal=maxVal;
	dataset.erase(dataset.begin()+0);	
	for(auto it =dataset.begin();it!=dataset.end();++it){
		long long int res=0;
	
		res=lcm(tempMaxVal, *it);
		if(res>maxVal)
			maxVal=res;
		
	}
	cout<<maxVal%1000000007<<endl;
	
}
 
 
int main() {
    long long int t,n,num;
    std::ios::sync_with_stdio(false);
	if(!(cin>>t))return 0;
	while(t--){
		
		cin>>n;
		if(n>1000||n<1)return 0;
		vector<long long int> data;
		while(n--){
			cin>>num;
			if(num>10000||num<1)return 0;
			data.push_back(num);
		}
		doAlgorithm(data);
		
	}
	return 0;
}