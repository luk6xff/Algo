#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>     
#include <string.h>

using namespace std;



//1st version using vector<bool> 
vector<bool> distinctNumbers(0x80000000); //for bitwise operation use 0x7FFFFFFF 2^31-1
const unsigned int mask = 0x80000000;
int main() { 
    unsigned long long N,S,P,Q;
    
    cin>>N>>S>>P>>Q;
    
    unsigned long long a;

    a= S%mask;
    distinctNumbers[a]=true;
    for(int i=1; i<N;i++)
    {
        a=(1ULL* a*P+Q)%mask;
        if(distinctNumbers[a]){
            cout<<i<<endl;
            return 0;
        }
        distinctNumbers[a]=true;
    }
    cout<<N<<endl;
    return 0;
}



//2nd version using int array  -> time performance improved!
unsigned int distinctIntegers[0x80000000>>5]; //x>>5 = x/(2^5) = x/32  
const unsigned int mask = 0x7FFFFFFF; //for bitwise operation use 0x7FFFFFFF 2^31-1
int main() { 
    unsigned long long N, nrOfDistinctIntegers=0;
    unsigned long long S,P,Q;
    
    cin>>N>>S>>P>>Q;
    
    unsigned long long a;
    memset(distinctIntegers,0,(N>>5)+1);
    a= S%mask;
    distinctIntegers[(a>>5)]= 1<<(a%32);
    ++nrOfDistinctIntegers;
    for(int i=1; i<N;i++)
    {
        a=(1ULL* a*P+Q)&mask;//for numbers 2^x --> modulo operation equals: z=y%(2^x) == z=y&((2^x) -1) 
        if(!(distinctIntegers[a>>5]&(1<<(a&(32-1)))))
        {
            distinctIntegers[a>>5]|=(1<<(a&(32-1)));
            ++nrOfDistinctIntegers;
        }

    }
    cout<<nrOfDistinctIntegers<<endl;
    return 0;
}