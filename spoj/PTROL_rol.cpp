//ROL
//Kod zadania: PTROL


#include <iostream>
using namespace std;



int main() {
	
	int nrOfTests;
	
	cin>>nrOfTests;
	if(nrOfTests<1)return 0;
	
	int n, firstNumber, num ;
	
	while(nrOfTests--){
		
		cin>>n;
		if(n>100)return  0;
		
		cin>>firstNumber;
		if(firstNumber>100)return  0;
		
		for(int i = 1; i<n; i++){
		 	
		cin>>num;	
			if(n>100)return  0;
			else cout<<num<<" ";
			
		}
		cout<<firstNumber<<endl;
		
		
	}
	
	// your code goes here
	return 0;
}
