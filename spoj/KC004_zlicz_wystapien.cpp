//1844. Zliczanie wystąpień
//Kod zadania: KC004
#include <iostream>
#include <vector>
using namespace std;


void doAlgorithm(vector<int>& dataset){
	
	int first_num = dataset.at(0);
	int result=0;
	vector<int>::iterator it= dataset.begin()+1;
	while( it!=dataset.end()){
		
		if(*(it++)==first_num)
		result++;
		
		
	}
	cout<<result<<endl;
	
}

int main() {
	int data,length;
	vector<int> dataset;
	while(1){
		if(!(cin>>data))break;
		dataset.push_back(data); //first element
		if(!(cin>>length))break;
		while(length--){
			if(!(cin>>data))break;
			dataset.push_back(data);
		}
			doAlgorithm(dataset);
			dataset.clear();
	}

	return 0;
}