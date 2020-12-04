#include <iostream>
#include <algorithm>    
#include <vector>       
using namespace std;
 
 
 
static void doAlgorithm(vector<int>& dataset){
	
	if(dataset.size()==0)
		return;
	int maxVal=0;
	int minVal= 99999999;
	sort(dataset.begin(),dataset.end());
	int i,k;
	for( i=0, k=dataset.size()-1; i<k;i++,k--){
		
		minVal= min(minVal, dataset.at(i)+dataset.at(k));
		maxVal= max(maxVal, dataset.at(i)+dataset.at(k));
	}
 
	cout<<maxVal-minVal<<endl;
	
}
 
 
int main() {
    int t,n,num;
    std::ios::sync_with_stdio(false);
	if(!(cin>>t))return 0;
	while(t--){
		
		cin>>n;
		if(n>100||n<1)return 0;
		vector<int> data;
		while(n--){
			cin>>num;
			if(num>10000||num<1)return 0;
			data.push_back(num);
		}
		doAlgorithm(data);
		
	}
	return 0;
}