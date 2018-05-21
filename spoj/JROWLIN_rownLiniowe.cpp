//1228. Równanie liniowe
//Kod zadania: JROWLIN
#include <iostream>
#include <iomanip>
using namespace std;

void doAlgorithm(float a, float b, float c){
     if(a==0&&b==c)cout<<"NWR"<<endl;
     else if(a==0){cout<<"BR"<<endl;}
     else{
     	
     	float result = (c-b)/a;
     	cout<<setprecision(2)<<fixed<<result<<endl;
     	
     }
}


int main()
{
	std::ios_base::sync_with_stdio(true);
	float a,b,c;
	cin>>a>>b>>c;
	doAlgorithm(a,b,c);
    
    return 0;
}



