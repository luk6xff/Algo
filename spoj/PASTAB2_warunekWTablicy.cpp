//3326. Warunek w tablicy
//Kod zadania: PASTAB2


#include <iostream>
#include <vector>
using namespace std;


void doAlgorithm(vector<long long>& dataset, char sign_, long long x){
	
	char sign = sign_;
	long long nr=x;
	
	for(int i =0; i<dataset.size();i++){
		switch(sign){
			
		case '<':
			  if(dataset.at(i)<nr) cout<<dataset.at(i)<<endl;
		break;
		
		case '>':
		      if(dataset.at(i)>nr) cout<<dataset.at(i)<<endl;
		break;
		}
	}
}


int main() {
	
	ios_base::sync_with_stdio(0);
	
	vector<long long> dataset;
	int nrOfData;
	char sign;
	long long x;
	cin>>nrOfData;
	if(nrOfData>1000||nrOfData<=0) return 0;
	while(nrOfData--){
		cin>>x;
		dataset.push_back(x);
	}
	cin>>sign;
	if(sign!='<'&&sign!='>')return 0;
	cin>>x;
	doAlgorithm(dataset,sign,x);
	return 0;
}
