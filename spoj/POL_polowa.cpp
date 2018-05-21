//1011. Połowa
//Kod zadania: POL
#include <iostream>
using namespace std;

void doAlgortithm(string &str){
	
 for(int i=0; i<str.length()/2;i++){
 	
 	cout<<str.at(i);
 	
 }	
	cout<<endl;
	
}


int main() {
	int nrOfTests;
	cin>>nrOfTests;
	if(nrOfTests<1||nrOfTests>100)return 0;
	cin.ignore();
	while(nrOfTests--){
		string data;
		
		getline(cin,data);
	//	cin.ignore();
		doAlgortithm(data);
	}
	return 0;
}
