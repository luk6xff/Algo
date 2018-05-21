//8090. Dzielenie pizzy
//Kod zadania: MWP3_3D


#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const double pi = acos(-1.0);



static void doAlgorithm(int d, int y){
	
	double perimeter = 2*pi*d/2;
	if(y%2) y=y*2;
	printf("%.3lf %d\n",  perimeter/y,y/2);
 
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int nrOfTests;
	int d,n;
	cin>>nrOfTests;
	if(nrOfTests<1||nrOfTests>100000) return 0;
    
    while(nrOfTests--){
    cin>>d>>n;
    if(d<10||d>100000000||n<3||n>1000000)return 0;

		doAlgorithm(d,n);
	}
    
	return 0;
}




