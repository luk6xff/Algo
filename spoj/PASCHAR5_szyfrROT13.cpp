//3456. Szyfrowanie ROT13
//Kod zadania: PASCHAR5

#include <iostream>
#include <vector>
using namespace std;



static char getRot13Char(char a){
	char ret;
	int length;
	if(a>='a'&&a<='z'){
		length = 'z'-a;
		if(length<13){
			ret = 'a'+(13-length-1);
		}
		else ret = a+13;
	}
	else if (a>='A'&&a<='Z'){
		length = 'Z'-a;
		if(length<13){
			ret = 'A'+(13-length-1);
		}
		else ret = a+13;
	}
	else ret= a;
	return ret;
}


static char getRot5Char(char a){
	char ret;
	int length;
	if(a>='0'&&a<='9'){
		length = '9'-a;
		if(length<5){
			ret = '0'+(5-length-1);
		}
		else ret = a+5;
	}
	else ret= a;
	return ret;
}

static void doAlgorithm(string& message){
 for(string::iterator it = message.begin();it!=message.end();it++ ){
 	if((*it<='Z'&&*it>='A')||(*it<='z'&&*it>='a')){
 			cout<<(char)(getRot13Char(*it));
 	}
 	else if(*it<='9'&&*it>='0'){
 		cout<<(char)(getRot5Char(*it));
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



