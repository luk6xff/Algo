//4138. princess Farida
//Kod zadania: FARIDA


#include <bits/stdc++.h>
using namespace std;

static long long int max(long long int a, long long int b){
	
	return a>b?a:b;
}

void doAlgorithm(vector<long int>& dataset,int nrOfTest){
	
	if(dataset.size()==0){
		cout<<"Case "<<nrOfTest<<": "<<"0"<<endl;
		return;
	}
	vector<long long int> dp;
	dp.push_back(dataset.at(0));
	if(dataset.size()==1){
		cout<<"Case "<<nrOfTest<<": "<<dp[0]<<endl;
		return;
	}
	dp.push_back(max(dp.at(0),dataset.at(1)));
	for(int i=2; i<dataset.size();++i){
	
		dp.push_back(max(dp[i-1],dataset.at(i)+dp[i-2]));	
	}
/*	
	for(auto coin: dp){
    	
    	cout<<coin<<" ";
    }
    cout<<endl;
*/
    cout<<"Case "<<nrOfTest<<": "<<dp.back()<<endl;
    
    
	
}


int main() {
    int N;  //nr of tests
    int nrOfM; //nr of monsters
    long int nrOfCoins; // nr of coins with each monster
    std::ios::sync_with_stdio(false);
	if(!(cin>>N))return 0;
	int temp = N;
	while(temp--){
		
		cin>>nrOfM;
		if(nrOfM>10000||nrOfM<0)
            return 0;
		vector<long int> data;
		while(nrOfM--){
			cin>>nrOfCoins;
            if(nrOfCoins>1000000000||nrOfCoins<0) 
                return 0;
			data.push_back(nrOfCoins);
		}
		doAlgorithm(data,N-(temp));
		
	}
	return 0;
}