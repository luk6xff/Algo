//601. NWD Kod zadania: PP0502B
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#define CHECK_RANGE(num, min, max)  (num<min||num>max)
									




void doAlgorithm(vector<int> data){
	
   	for(int i =0;i<data.size();i++)
	{
  		cout<<data.at(data.size()-i-1)<<" ";
    }
    cout<<endl;
}



int main() {

int t; //nr of tests
vector<vector<int> > dataVector;
int nrOfNumbers,number;
cin>>t;
//	if(t>80||t<1)
//	return 0;
while(t--){
	cin>>nrOfNumbers;
	if(CHECK_RANGE(nrOfNumbers,1,100))
		return 0;
		vector<int> data;
    while(nrOfNumbers--){
    	cin>>number;
    	data.push_back(number);
    }	
	dataVector.push_back(data);
}
	for(int i =0;i<dataVector.size();i++)
	{
  		doAlgorithm(dataVector.at(i));
    }
	return 0;
}
