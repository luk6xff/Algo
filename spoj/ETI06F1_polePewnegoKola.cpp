//609. Pole pewnego koła
//Kod zadania: ETI06F1

#include <iostream>
#include <iomanip>
using namespace std;

#define PI  3.141592654

int main()
{
	std::ios_base::sync_with_stdio(false);
    double r,d;
    
    cin>>r>>d;
    
    cout<<setprecision(2)<<fixed<< (PI* (r*r - d*d / 4))<<endl;

	return 0;
}



