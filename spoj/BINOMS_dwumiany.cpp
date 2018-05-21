//833. Dwumiany
//Kod zadania: BINOMS


#include <iostream>
using namespace std;

void doAlgorithm(long n, long k){

long long result=1;	
	
	for(int i = 1;i<=k;i++){
		result=result*(n-(k-i))/i;
	}
		cout<<result<<endl;
	}
int main() {
	long long T,n,k;
	cin>>T;
	if(T>10000) return 0;
	
	while(T--){
	cin>>n;
	cin>>k;
	doAlgorithm( n, k);
	}
	return 0;
}
