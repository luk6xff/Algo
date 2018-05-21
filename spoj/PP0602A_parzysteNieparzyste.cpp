//1055. Parzyste nieparzyste
//Kod zadania: PP0602A
#include <iostream>
#include <vector>
using namespace std;

void doAlgorithm(vector<int>& dataset){
	
	for(int i = 1; i<dataset.size(); i+=2){
		
		cout<<dataset.at(i)<<" ";
	}
	for(int i = 0; i<dataset.size(); i+=2){
		cout<<dataset.at(i)<<" ";
	}
		cout<<endl;
	
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
			data.push_back(num);
		}
		doAlgorithm(data);
		
	}
	


		
		
	

	return 0;
}
