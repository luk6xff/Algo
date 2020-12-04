/*


Problem Statement


Time is running out. You have a final match to play as a counter terrorist. You have N players each having a distinct ID from 1 to N. You have to choose some players on your team from these N players such that no two chosen players have consecutive numbers (as they tend to kill each other). Also you definitely have to choose some K players whose numbers are given. They are the snipers. Find the maximum number of players that you can choose.


Input Format


The first line contains 2 space-separated integers, N and K, where N is the total number of players and K is the number of players that have to be definitely in the team (the snipers). 
 The second line contains K space-separated integers that are the IDs of the snipers.

NOTE: There are no two snipers with consecutive numbers.

Constraints 
2≤N≤2×106 
1≤K≤N/2 
1≤ ID of each sniper ≤N


Output Format


You need to print the maximum number of players that you can have in your team.


Sample Input

8 2
6 2



Sample Output

4



Explanation


There are 8 players in total, among which you have to definitely choose players with ID 2 and 6. 
 To maximize the number of players in the team, you will choose the players with IDs 4 and 8, so that you will have a total of 4 players. 


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    int N, K;
    
    cin>>N>>K;
    unordered_set<int> warriorsId;
    int i =K;
    int id;
    while(i--){
        cin>>id;
        warriorsId.insert(id);
    }
    
    for(int x= 1;x<=N;x++){
        
        if((warriorsId.find(x)==warriorsId.end()&&warriorsId.find(x+1)==warriorsId.end()&&warriorsId.find(x-1)==warriorsId.end()))         {
            warriorsId.insert(x);
            K++;
        }
    }
    cout<<K<<endl;
    return 0;
}
