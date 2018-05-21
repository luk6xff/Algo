//1035. Test 3
//Kod zadania: PP0601A2
#include <iostream>
using namespace std;

int main() {
	int previousNum=42;
	int data;
	int counter=0;
	
	while(counter<3){
	
		if(!(cin>>data))break;
		
		if(previousNum!=42&&data==42){counter++;}
		
		previousNum=data;
		cout<<data<<endl;
		
	}
	return 0;
}
