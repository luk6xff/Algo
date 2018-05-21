//1910. Odwracanie wyrazów
//Kod zadania: KC009

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string text;
	while(getline(cin,text)){
		
		std::reverse(text.begin(),text.end());
		cout<<text<<endl;
		text.clear();
		
	}
	return 0;
}

