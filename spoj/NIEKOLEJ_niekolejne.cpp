//1211. Niekolejne
//Kod zadania: NIEKOLEJ

#include <iostream>
using namespace std;



void doAlgorithm(int n){
	
	if(n==0) {
		cout<<0<<endl; return;
	}
	
	if(n==1||n==2) {
		cout<<"NIE"<<endl; return;
	}
	if(n==3){
		cout<<2<<" "<<0<<" "<<3<<" "<<1<<" "<<endl; return;
	}
	cout<<0<<" ";
	for(int i =1;i<=n;i++){
		if(!(i%2))
		cout<<i<<" ";
	}
	for(int i =1;i<=n;i++){
		if(i%2)
		cout<<i<<" ";
	}
	cout<<endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	
	cin>>n;
	if(n<0||n>1000000) return 0;
    doAlgorithm(n);
	return 0;
}
