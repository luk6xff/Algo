//2181. Wycinanie literek
//Kod zadania: PROGC05

#include <iostream>
using namespace std;

bool doAlgorithm(string &data){
	
	if(data.at(0)>'z'||data.at(0)<'a'||data.at(1)!=' ') return false;
	for(int i =2; i<data.length();i++){
	if(data.at(i)>'z'||data.at(i)<'a') return false;	
		
	}
	char sign = data.at(0);
	//cout<<"SIGN:"<<sign<<data.at(1)<<data.at(2)<<endl;
	for(int i = 2; i<data.length();i++){
		if(sign==data.at(i)){
		  data.erase(i,1);
		  i--;
		}
		
	}
	for(int i = 2; i<data.length();i++){
		cout<<data.at(i);
		
	}
	cout<<endl;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	string data;
	while(getline(cin,data)){
		doAlgorithm(data);
	}
	return 0;
}
