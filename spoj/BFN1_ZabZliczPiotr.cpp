//568. Zabawne Dodawanie Piotrusia 
//Kod zadania: BFN1

#include <iostream>
#include <vector>
#include <numeric>
#include <sstream>
using namespace std;

bool isPalindrome(int x){
	stringstream ss;
	ss<<x;
	//cout<<ss.str();
	for(int i = 0; i<ss.str().length(); i++){
		if(ss.str().at(i)!=ss.str().at(ss.str().length()-i-1))
		return false;
	}
	return true;
}

void addOppositeNumber(int& x){
	int opposite=0;
	stringstream ss;
	ss<<x;
	string temp = ss.str();
	for(int i = 0; i<temp.length()/2; i++){
	  char a =temp.at(i);
	  temp.at(i) =temp.at(temp.length()-i-1) ;
	  temp.at(temp.length()-i-1)=a;
	}
	//cout<< "TEMP: " <<temp<<endl;
	stringstream strToInt(temp);
	int result=0;
    strToInt >> result;
	x+=result;
	//cout<< "TEMP: " <<x<<endl;
}

void doAlgorithm(int x){
	
	int counter =0;
	while(1){
	 if(!isPalindrome(x))
        addOppositeNumber(x);
     
     else break;
     counter++;
	}
    cout<<x<<" "<<counter<<endl;
}



int main() {

int nrOfNumbers;
vector<int> dataVector;	
int data;
cin>>nrOfNumbers;
	if(nrOfNumbers>80||nrOfNumbers<1)
	return 0;
while(nrOfNumbers--){
	cin>>data;
	if(data>80||data<1)
		return 0;
	dataVector.push_back(data);
}
	for(int i =0;i<dataVector.size();i++)
	{
        //cout<<"IS_PALIND : "<<isPalindrome(dataVector.at(i))<<endl;
        //if(!isPalindrome(dataVector.at(i)))
        //addOppositeNumber(dataVector.at(i));
        doAlgorithm(dataVector.at(i));
        
        //cout<<dataVector.at(i)<<endl;
	}
	return 0;
}


#include <iostream>
using namespace std;

int main() {
	cout<<"Mundial "<<(char)('<'-'\n')<<(char)(':'-'\n')<<(char)(';'-'\n')<<(char)('>'-'\n')<<endl;
	return (char)(':'-':');
}
