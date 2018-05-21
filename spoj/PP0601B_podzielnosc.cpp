//1032. Podzielność
//Kod zadania: PP0601B
#include <iostream>
#include <vector>
using namespace std;

void doAlgorithm(vector<int>& dataset){
	
	if(dataset.size()>3)return;
	
	for(int i =2; i<dataset.at(0);i++){
	  	
	  	if(!(i%dataset.at(1))&&(i%dataset.at(2))) {
	  		
	  		cout<<i<<" ";
	  		}
	 }
	 cout<<endl;
}


int main() {
int nrOfTests,n,x,y;

	cin>>nrOfTests;
	if(nrOfTests<1)return 0;
	cin.ignore();
	while(nrOfTests--){
	vector<int> dataset;	
	cin>>n;	
	cin>>x;	
	cin>>y;	
	if(n>100000&&n<1)return 0;
		dataset.push_back(n);	
		dataset.push_back(x);
		dataset.push_back(y);
		doAlgorithm(dataset);
		
	}

	return 0;
}
