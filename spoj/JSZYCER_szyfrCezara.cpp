//1300. Szyfr Cezara
//Kod zadania: JSZYCER

#include <iostream>
#include <vector>
using namespace std;


static void doAlgorithm(string& message){
 
 for(string::iterator it = message.begin();it!=message.end();it++ ){
 	
 	if(*it<='Z'&&*it>='A'){
 		
 		if(*it=='X')
 		  cout<<('A');	
 	    else if(*it=='Y')
 	      cout<<('B');
 	    else if(*it=='Z')
 	      cout<<('C');
 	    else
 			cout<<(char)(*it+3);
 	}
 	else cout<<(char)*it;
 	
 }
 cout<<endl;
}

int main()
{
	std::ios_base::sync_with_stdio(false);


    string codedMessage;
	while(getline(cin,codedMessage)){
		doAlgorithm(codedMessage);
	}
    
	return 0;
}



