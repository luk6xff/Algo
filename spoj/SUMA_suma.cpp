//968. Suma
//Kod zadania: SUMA

#include <iostream>
using namespace std;


int main() {	
	long long res= 0;
	long long n= 0;

	
	while(cin>>n){

	//if(cin.eof()) return 0;
	if(n<-100||n>100)return 0;
	res+=n;
    cout<<res<<endl;
	
	}
	return 0;
}
