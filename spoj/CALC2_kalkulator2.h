//998. Kalkulator 2
//Kod zadania: CALC2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {	
	
	int num1,num2,result;
	char sign;
	
	vector<int> registers(10);
    for(int i= 0; i<registers.size();i++){
        registers.at(i)=0;	
   	}

    while(1){
    	
    
    if(!(cin>>sign)) break;
    if(!(cin>>num1)) break;
    if(!(cin>>num2)) break;
 	
 	switch(sign){
 		case 'z':registers.at(num1)= num2;
 		break;
 		case '+':result = registers.at(num1)+registers.at(num2);
 		break;
 		case '-':result = registers.at(num1)-registers.at(num2);
 		break;
 		case '*':result = registers.at(num1)*registers.at(num2);
 		break;
 		case '/':result = registers.at(num1)/registers.at(num2);
 		break;
 		case '%':result = registers.at(num1)%registers.at(num2);
 		break;
 		default: 
 		return 0;
 		
 	}
  if(sign!='z')
  	cout<<result<<endl;
 }

	return 0;
}

