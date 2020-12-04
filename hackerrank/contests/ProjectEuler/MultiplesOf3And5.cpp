
//BRUTFORCE - not effective
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    unsigned int N;
    unsigned long long sum=0;
    unsigned long long multi3=0;
    unsigned long long multi5=0;
    unsigned long long multi5And3=0;
    unsigned long long stop=0;
    cin>>T;
    
    while(T--){
        
        cin>>N;
        sum=0;

        for(int i=3; i<N; i++)
        {
          if(!(i%3)||!(i%5))
            sum+=i;
        }
        
        cout<<sum<<endl;
    }
    return 0;
}
