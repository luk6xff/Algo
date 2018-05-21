//1016. Predkość średnia
//Kod zadania: VSR
#include <iostream>
using namespace std;

int main() {
	int nrOfTests,v1,v2;
	cin>>nrOfTests;
	if(nrOfTests<1||nrOfTests>1000)return 0;
	cin.ignore();
	while(nrOfTests--){
		string data;
		
	     cin>>v1;
	     cin>>v2;
	     if(v1<1||v1>10000||v2<1||v2>10000)return 0;
         
         cout<<((2*v1*v2)/(v1+v2))<<endl;
	}
	return 0;
}
