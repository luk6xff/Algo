//1830. Nierówność trójkąta
//Kod zadania: KC003
#include <iostream>
using namespace std;

int main() {
	float a,b,c;
	//cin.ignore();//>>a>>b>>c;
	while(1){
		
		if(!(cin>>a))break;
		if(!(cin>>b))break;
		if(!(cin>>c))break;
		
		if((a<(b+c))&&(b<(a+c))&&(c<(a+b)))
			cout<<1<<endl;
		else 
			cout<<0<<endl;
	}
	return 0;
}

