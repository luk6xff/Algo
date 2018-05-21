//549. Proste dodawanie Kod zadania: RNO_DOD
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {

int nrOfTests;
int nrOfNrToBeSummed;
vector<vector<long int> > dataVector;	
vector<long int> data;
long int nr;
cin>>nrOfTests;
	if(nrOfTests>99||nrOfTests<1)
	return 0;
	signed long long result=0;
while(nrOfTests--){
	
	cin>>nrOfNrToBeSummed;
	while(nrOfNrToBeSummed--){ 
		cin>>nr;
		//data.push_back(nr);
		result+=nr;
	}
	// dataVector.push_back(data);
	cout<<result<<endl;
	result=0;
}


/*	for(int i =0;i<dataVector.size();i++)
	{

	    result=(double)accumulate(dataVector.at(i).begin(),dataVector.at(i).end(),0)-result;
        cout<<result<<endl;
	}
*/
	return 0;
}
