//Samolot
//Kod zadania: POTSAM


#include <iostream>
using namespace std;

int main()
{
    bool i=true;
uint16_t n1=0, k1=0, n2=0, k2=0;
while(i){cin>>n1>>k1>>n2>>k2;
if(n1<1){continue;}
else if(k2>1000){continue;}
else i=false;}
cout<<"\n"<<(n1*k1+n2*k2);
    return 0;
}
