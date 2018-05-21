//1909. Sumy wielokrotne
//Kod zadania: KC008

#include <iostream>
#include <string>
using namespace std;

int main() {
	
	long long sumAll=0;

/*   
    while(true){
    	long long sum=0;
		long long  num=0;
		bool isOver =false;
    	while(true){
			cin>>num;
			if(num==' ')break;
			sum+=num;
			if(cin.eof()){isOver=true;break;}
	  		if(cin.peek()=='\n')break;
	  	}	
    	cout<<sum<<endl;
    	sumAll+=sum;
    	if(isOver)break;
    
    }
    */
    
    
    	long long sum=0;
		long long  num=0;
    	while(cin>>num){
		    
			if(num!=0){
				sum+=num;
			}
			else{sumAll+=sum;
			cout<<sum<<endl;
				sum=0;
				num=0;
			}

	  	}	
	cout<<sumAll<<endl;
	return 0;
}

