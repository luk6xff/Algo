//1276. Spacje
//Kod zadania: JSPACE

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


static void doAlgorithm(string& text){
 //cout<<text<<endl;
 
 for(string::iterator it=text.begin(); it!=text.end();it++){
 	string::iterator lastErasedIt;
 	if(*it==' '){
 		lastErasedIt=text.erase(it);
 		it--;
 	//	cout<<*(lastErasedIt)<<*it<<endl;
 	if((*(lastErasedIt)>='a')&&(*(lastErasedIt)<='z'))
 		*(lastErasedIt)=*(lastErasedIt)-32;
 	}
 }
 cout<<text<<endl;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
//	cin.ignore();
string text;
do
{	string temp;
	getline(cin,temp);
	doAlgorithm(temp);
	//text.append(temp);
}while(!cin.eof());
//doAlgorithm(text);
	
	return 0;
}



