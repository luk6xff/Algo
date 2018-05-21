//1019. Systemy pozycyjne
//Kod zadania: SYS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void doAlgorithm(int dataToBeConverted){
	const char* characters ={"0123456789ABCDEF"};
	int temp =  dataToBeConverted;
	int base16 =16;
	int base11 =11;
	string data16, data11;
	do{
		data16.push_back(characters[temp%base16]);
		temp/=base16;
	}while(temp>=base16);
	if(temp>0)
	data16.push_back(characters[temp]);
	temp =  dataToBeConverted;
	do{
		data11.push_back(characters[temp%base11]);
		temp/=base11;
	}while(temp>=base11);
	if(temp>0)
	data11.push_back(characters[temp]);
	
	std::reverse(data16.begin(),data16.end());
	std::reverse(data11.begin(),data11.end());
    cout<<data16<<" "<<data11<<endl;
/*
	for(string::iterator it16 =data16.begin();it16<data16.end(); ++it16 ){
		cout<<*it16;
	}
	cout<<" ";	
	for(string::iterator it11 =data11.begin();it11<data11.end(); ++it11 ){
		cout<<*it11;
	}
	cout<<endl;
*/
}



int main() {
	int nrOfTests;
	vector<int> dataset;
	int data;
	cin>>nrOfTests;
	if(nrOfTests<1||nrOfTests>10000)return 0;
//	cin.ignore();
	while(nrOfTests--){
		 cin>>data;
	     if(data<1||data>1000000)return 0;
         dataset.push_back(data);
        
	}
	
	for(int i = 0; i<dataset.size();i++){
		doAlgorithm(dataset.at(i));
	}
	return 0;
}


