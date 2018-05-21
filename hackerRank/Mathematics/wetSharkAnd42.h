/*

Problem Statement

As punishment for attacking Sunland, Wet Shark is now forced to walk on a line of numbered squares, starting from 1 and going to infinity. Wet Shark initially has a strength of S. To make the experience harder for Wet Shark, each square that has a label divisible by 4 and/or 2 but not divisible by 42 contains a black glob of jelly, stepping on which his strength decreases by 1.

Wet Shark does not know that this line of squares is infinitely long, and he is determined to continue walking until his strength reaches 0. Wet Shark walks from square to square, so he starts at square 1, goes to square 2, then 3, then 4, etc.

Wet Shark’s punisher needs your help, and wants to compute where Wet Shark will stop in order to meet him there and punish him. Given Wet Shark’s initial strength S, find the square on which Wet Shark’s strength will reach 0. Wet Shark can go far if defenses are not strong enough, so please output the answer modulo 109+7. Wet Shark is curious, so he wants to know that given S strength initially, how far he will go for different values S. Help him figure out how long he can go without doom for each S.

Input Format

The first line of the input contains an integer T, the number of queries. The following lines describe the queries.

Each query consists of a line containing a single integer, which is the value of S.

Output Format

Print T lines, each line containing the answer for each query, i.e. the last square Wet Shark will reach before he runs out of strength, starting with a strength of S, modulo 109+7.

Constraints

1≤T≤100 
1≤S≤1018

Sample Input

2
3
4
Sample Output

6 
8
Explanation

Square 1: 3 strength 
Square 2: 2 strength 
Square 3: 2 strength 
Square 4: 1 strength 
Square 5: 1 strength 
Square 6: 0 strength

Thus the answer is 6.

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// not accepted version
int main() {
    int T;
    long long unsigned int S;
    
    cin>>T;
    if(T<1||T>100)
        return 0;
    while(T--){
        
        
        cin>>S;
        long long unsigned int nrOfSquares=0;
        long long unsigned int nrOf42Squares=0;
        
        nrOfSquares=S*2;
        nrOf42Squares =nrOfSquares/42;  
        if(nrOf42Squares!=0){
            if(nrOf42Squares<21)
                nrOfSquares=nrOfSquares+(2*nrOf42Squares);
            else if(nrOf42Squares>=21){
                while(nrOf42Squares>=21){
                    
                    nrOfSquares=nrOfSquares+(2*nrOf42Squares); 
                    nrOf42Squares= nrOf42Squares/21;
                    

                }
                 nrOfSquares=nrOfSquares+(2*(nrOf42Squares));
            }
        }

        
        cout<<nrOfSquares%1000000007<<endl;
    }
    return 0;
}


//accepted version:
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    long long unsigned int S;
    
    cin>>T;
    if(T<1||T>100)
        return 0;
    while(T--){
        
        
        cin>>S;
        long long unsigned int nrOfSquares=0;
        long long unsigned int temp=0;
        long long unsigned int nrOfSquares42=0;
        
        nrOfSquares=S;
        nrOfSquares42=S/20;
        temp=nrOfSquares%20;
        if(!temp)
            nrOfSquares=(42*nrOfSquares42)-2;
        else
            nrOfSquares=(42*nrOfSquares42)+(2*temp);

        
        cout<<nrOfSquares%1000000007<<endl;
    }
    return 0;
}