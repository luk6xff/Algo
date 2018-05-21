//601. NWD Kod zadania: PP0501A
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


#define CHECK_RANGE(num, min, max)  (num<min||num>max)
									
int nwd(int a ,int b){
	
/*	int lowerOne= (a<b)?a:b;	
	
	for(int i =lowerOne; i!=0; i--){
		
		if(a%i==0 && b%i==0 )return i;
	}
	*/
	int t=0;
while(b)
  {
    t = b;
    b = a % b;
    a = t;
  } 
  return a;
}



void doAlgorithm(int a, int b){
	
    cout<<nwd(a ,b)<<endl;
}



int main() {

int t; //nr of tests
vector<pair<int,int> > dataVector;	
int data1,data2;
cin>>t;
//	if(t>80||t<1)
//	return 0;
while(t--){
	cin>>data1;
	if(CHECK_RANGE(data1,0,1000000))
		return 0;
	cin>>data2;
	if(CHECK_RANGE(data2,0,1000000))
		return 0;	
	dataVector.push_back(make_pair(data1, data2));
}
	for(int i =0;i<dataVector.size();i++)
	{
  		doAlgorithm(dataVector.at(i).first,dataVector.at(i).second);
    }
	return 0;
}
