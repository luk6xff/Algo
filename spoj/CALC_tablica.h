//977. Tablica
//Kod zadania: TABLICA

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {	
	vector<int> data;
	int num1,num2;
    char sign;
    int result;

    while(1/*!cin.eof()*/){
    	
    
    if(!(cin>>sign)) break;
    if(!(cin>>num1)) break;
    if(!(cin>>num2)) break;
 	
 	switch(sign){
 		case '+':result = num1+num2;
 		break;
 		case '-':result = num1-num2;
 		break;
 		case '*':result = num1*num2;
 		break;
 		case '/':result = num1/num2;
 		break;
 		case '%':result = num1%num2;
 		break;
 		default: 
 		return 0;
 		
 	}
 	
  cout<<result<<endl;
 }

	return 0;
}

