#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; 
    cin>>T;
    while(T--)
    {
        int N;
        cin>> N;
        vector<int> vec(N);
        for(int i=0;i<N;i++)
        {
           cin>>vec[i]; 
        }
        
        long long contiguousSum=0;
        long long notContiguousSum=0;
        long long maxSum=vec[0];
        int sign=vec[0];
        
        for(int i =0;i<vec.size();i++)
        {
            //checks if only '-' number exist 
            if(sign<vec[i])
               sign=vec[i];            
            //contiguous
            contiguousSum= ((contiguousSum+vec[i])>=0)?contiguousSum+vec[i]:0;
            if(maxSum <contiguousSum)
            {
               maxSum =contiguousSum; 
            }
            
            //not contiguous
            notContiguousSum= (notContiguousSum+vec[i]>notContiguousSum)?notContiguousSum+vec[i]:notContiguousSum;
                        
        }
        if(sign<0)
        {
          cout<<sign<<" "<<sign<<endl;  
        }
        else
        {
          cout<<maxSum<<" "<<notContiguousSum<<endl;
        }
    }
    return 0;
}
