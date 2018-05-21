//1978. Zliczanie linii
//Kod zadania: PROGC01

#include <iostream>
using namespace std;

int main() {
	
string data;

int numOfLines= 0;
while(getline(cin,data)){
	numOfLines++;	
}

cout<<numOfLines<<endl;	
	return 0;
}
