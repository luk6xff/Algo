//522. PrzedszkolankaKod zadania: PRZEDSZK
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#define CHECK_RANGE(num, min, max)  (num<min||num>max)
									




void doAlgorithm(vector<int> data){
	
	int biggerValue=data.at(0)<data.at(1)?data.at(1):data.at(0);
	int lowerValue= data.at(0)<data.at(1)?data.at(0):data.at(1);
	
	int temp=biggerValue;
//	cout<<temp<<lowerValue;
   	while(1)
	{
		if(!(temp%lowerValue)) break;
		temp+=biggerValue;
   }
    cout<<temp<<endl;
}



int main() {

int t; //nr of tests
vector<vector<int> > dataVector;
int number;
cin>>t;

while(t--){

		vector<int> data;
    	cin>>number;
    	if(CHECK_RANGE(number, 10, 30))return 0;
    	data.push_back(number);
    	cin>>number;
        if(CHECK_RANGE(number, 10, 30))return 0;
    	data.push_back(number);
        dataVector.push_back(data);
    }	


	for(int i =0;i<dataVector.size();i++)
	{
  		doAlgorithm(dataVector.at(i));
    }
	return 0;
}
