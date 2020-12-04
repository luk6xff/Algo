/*

Problem Statement

Русский \| 中文

Mark is an undergraduate student and he is interested in rotation. A conveyor belt competition is going on in the town which Mark wants to win. In the competition, there's A conveyor belt which can be represented as a strip of 1xN blocks. Each block has a number written on it. The belt keeps rotating in such a way that after each rotation, each block is shifted to left of it and the first block goes to last position.

There is a switch near the conveyer belt which can stop the belt. Each participant would be given a single chance to stop the belt and his PMEAN would be calculated.

PMEAN is calculated using the sequence which is there on the belt when it stops. The participant having highest PMEAN is the winner. There can be multiple winners.

Mark wants to be among the winners. What PMEAN he should try to get which guarantees him to be the winner.

PMEAN=∑i=1ni×a[i]
where a represents the configuration of conveyor belt when it is stopped. Indexing starts from 1.

Input Format 
First line contains N denoting the number of elements on the belt. 
Second line contains N space separated integers.

Output Format 
Output the required PMEAN

Constraints 
1 ≤ N ≤ 106 
-109 ≤ each number ≤ 109 
For any rotation, PMEAN will always lie within the range of 64-bit signed integer.

Sample Input

3
20 30 10 
Sample Output

140
Explanation

Number on top can be written in these manners. 
Initial numbers on belt, 20 30 10 PMEAN = 1x20 + 2x30 + 3x10 = 110 
After first rotation, 30 10 20 PMEAN = 1x30 + 2x10 + 3x20 = 110 
After second rotation, 10 20 30 PMEAN = 1x10 + 2x20 + 3x30 = 140 
So maximum possible value will be 140.

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <numeric>
using namespace std;


int main() {
    int N;
    long long int M;
    long long int PMEAN=0x8000000000000000;
    long long int tempPMEAN=0;
    long long int sum=0;
    std::vector<long long int> mVector; 
    cin>>N;
    
    long long int i = 0;
    while(i<N){
        cin>>M;
        mVector.push_back(M);
        sum+=M;
        i++;
    }
    i=0;
    while(i<N){
        tempPMEAN+=((i+1)*mVector.at(i));
        i++;
    }
    
    i=0;
    while(i<(N)){  
        tempPMEAN-=sum;
        tempPMEAN+=((N)*mVector.at(i));
        
        PMEAN=  PMEAN>tempPMEAN?PMEAN:tempPMEAN;
        i++;      
    }
    cout<<PMEAN<<endl;
    return 0;
}