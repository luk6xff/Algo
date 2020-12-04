/*

Problem Statement


There are N toilets in a row indexed from 1 to N. At a time, 2 people enter the washroom. The degree of dirtiness of each toilet is 0 initially and it increases by 1 after it is used each time. The 1st person occupies the 1st toilet with the lowest degree of dirtiness moving from 1 to N. The 2nd person occupies the toilet with the lowest degree of dirtiness moving from N to 1. The next two people enter the toilet when the first two people have left. Find the index of toilet and degree of dirtiness for the Mth person. 

Note In case M is odd, the last person walks into the washroom alone and occupies the least dirty toilet moving from 1 to N.

Input Format 
 The first line contains T, the number of test cases. Each test case consists of one line containing N, the number of toilets, and M, the person to enter the toilet, seperated by space.

Output Format 
 The index of the toilet used by M and its degree of dirtiness D. 

Constraints 
1≤T≤10 
1≤N≤50000 
1≤M≤106 

Sample Input
3  
10 3  
5 8  
4 26 


Sample Output
2 0  
4 1  
4 6  


Explanation

In the second test case, 
 for the first two persons, positions are 1 _ _ _ 2, degree of dirtiness 0 0 0 0 0 (dirtiness is 0 since they are the first to use it) 
 for person 3 and 4, positions are _ 3 _ 4 _ , degree of dirtiness 1 0 0 0 1 
 for 5 and 6, positions are _ _ 5 _ 6, degree of dirtiness 1 1 0 1 1 
 for 7 and 8, positions are 7 _ _ 8 _, degree of dirtiness 1 1 1 1 2 so the answer is 4,1

*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static void doAlgorithm(int N , int M){
    int nrOfMoves;
    vector<int> dirtiness(N);   
    if(M==1)
    {
        cout<<1<<" "<<0<<endl;
        return;
    }

    if(M%2)
        nrOfMoves= M/2+1;
    else 
        nrOfMoves= M/2;
    
    int idxPerson1=0;
    int idxPerson2=N-1;
    dirtiness[idxPerson1]++;
    dirtiness[idxPerson2]++;
    nrOfMoves--;
    while(nrOfMoves--){
        idxPerson1++;
        if(idxPerson1>=dirtiness.size()){
           idxPerson1=0; 
        }
        else if(dirtiness[idxPerson1]>=dirtiness[idxPerson1-1]){
           idxPerson1=0;
        }
        dirtiness[idxPerson1]++; 
        
        idxPerson2--;
        if(idxPerson2<0){
           idxPerson2=0; 
        }
        else if(dirtiness[idxPerson2]>=dirtiness[idxPerson2+1]){
           idxPerson2=N-1;
        }
        dirtiness[idxPerson2]++; 
    }
    if(M%2){
      if(N==1)
          cout<<idxPerson1+1<<" "<<dirtiness[idxPerson1]-1-1<<endl;
      else 
          cout<<idxPerson1+1<<" "<<dirtiness[idxPerson1]-1<<endl;
    }
    else  cout<<idxPerson2+1<<" "<<dirtiness[idxPerson2]-1<<endl;
}

int main() {
    int T; //test cases
    int N; //nr of toilets
    int M; //nr of persons
    cin>>T;
    if(T<1||T>10){
        return 0;
    }
    while(T--){
        
        cin>>N>>M;
        if(N<1||N>500000||M<1||M>1000000)
            return 0;
        doAlgorithm(N,M);
    }  
    return 0;
}
