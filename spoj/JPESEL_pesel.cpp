//1261. Pesel
//Kod zadania: JPESEL

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

#define CONVERT_CHAR_TO_INT(x) (x-'0')

static void doAlgorithm(string& pesel){

 int sum = CONVERT_CHAR_TO_INT(pesel.at(0))*1   						  \
 +CONVERT_CHAR_TO_INT(pesel.at(1))*3+CONVERT_CHAR_TO_INT(pesel.at(2))*7   \
 +CONVERT_CHAR_TO_INT(pesel.at(3))*9+CONVERT_CHAR_TO_INT(pesel.at(4))*1   \
 +CONVERT_CHAR_TO_INT(pesel.at(5))*3+CONVERT_CHAR_TO_INT(pesel.at(6))*7   \   
 +CONVERT_CHAR_TO_INT(pesel.at(7))*9+CONVERT_CHAR_TO_INT(pesel.at(8))*1   \
 +CONVERT_CHAR_TO_INT(pesel.at(9))*3+CONVERT_CHAR_TO_INT(pesel.at(10))*1;
 
 if(!(sum%10))
   cout<<"D"<<endl;
 else 
   cout<<"N"<<endl;
   	
}


int main()
{
	std::ios_base::sync_with_stdio(true);
	int N;
	cin>>N;
	if(N>100||N<1)return 0;
	cin.ignore();
	while( N--){
     string pesel;
	   getline(cin,pesel);
	   doAlgorithm(pesel);
	}
	
	return 0;
}



