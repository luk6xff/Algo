//1911. Zliczanie liczb i wyrazów
//Kod zadania: KC010

#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;


static void doAlgorithm(string& text){

//	cout<<text<<endl;
	int numCounter=0; 
	int wordCounter=0;
	bool word =false;
	bool num =false;
	char prevChar='-';
	for(string::iterator it =text.begin();it!=text.end();it++){
		
		
		if(isalpha(prevChar)||isalpha(*it)){
			
			word =true;
		//	cout<<"1 " ;
		}
		if(isdigit(prevChar)||isdigit(*it)){
			
			num =true;
		//	cout<<"2 " ;
			
		}
		
		if(isalpha(prevChar)&&isdigit(*it)){
			
			word =false;
		//	cout<<"3 " ;
		}
		if(isdigit(prevChar)&&isalpha(*it)){
			
			num =false;
		//	cout<<"4 ";
		}
		
		if(word==true&&((*it==' ')||(it==(text.end()-1)))){
		  wordCounter++;
		  word =false;
		  //cout<<"5 ";
		}
		if(num==true&&((*it==' ')||(it==(text.end()-1)))){
		  numCounter++;
		  num =false;
		  //cout<<"6 ";
		}
		
		
		prevChar= *it;
	}
	cout<<numCounter<<" "<<wordCounter<<endl;
	
}


int main() {
	std::ios_base::sync_with_stdio(false);
	string text;
	while(getline(cin,text)){

		doAlgorithm(text);
		text.clear();
	}
	return 0;
}

