#include <iostream>
#include <algorithm>    
#include <vector>       
using namespace std;
 
 
 
static void doAlgorithm(int L,int R, int K,vector<int>& dataset){
	
	if(dataset.size()==0)
		return;
	long long int sum=0;
	while(L <= R){
        sum = sum + dataset[L-1];
        L = L + K; 
	}
	cout<<sum<<endl;
	
}
 
 
int main() {
    int N,Q,Ai,L,R,K;
    vector<int> data;
    std::ios::sync_with_stdio(false);
	cin>>N>>Q;
	while(N--){
		
		cin>>Ai;
		if(Ai>100000||Ai<0)return 0;
		data.push_back(Ai);		
	}
	while(Q--){
		
		cin>>L>>R>>K;
		if(L<1/*TODO more */)return 0;
		doAlgorithm(L,R,K,data);
		
	}
	return 0;
}