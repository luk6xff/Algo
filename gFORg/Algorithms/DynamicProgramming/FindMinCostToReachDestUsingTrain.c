// Input: 
// cost[N][N] = { {0, 15, 80, 90},
              // {INF, 0, 40, 50},
              // {INF, INF, 0, 70},
              // {INF, INF, INF, 0}
             // };
// There are 4 stations and cost[i][j] indicates cost to reach j 
// from i. The entries where j < i are meaningless.

// Output:
// The minimum cost is 65
// The minimum cost can be obtained by first going to station 1 
// from 0. Then from station 1 to station 3.


#include<iostream>
#include<climits>
using namespace std;
 
#define INF INT_MAX
#define N 4

//dynamic programming solution
int minCost(int cost[][N]){

    int dist[N];
    for(int i=0;i<N;i++)
        dist[i]=INF;
    dist[0]=0;



    for(int i =0; i<N;i++){
        for(int j =i+1;j<N;j++){
            if(dist[j]>dist[i]+cost[i][j])
               dist[j]=dist[i]+cost[i][j];
        }
        return dist[N-1];
    }
}

int main()
{
    int cost[N][N] = { {0, 15, 80, 90},
                      {INF, 0, 40, 50},
                      {INF, INF, 0, 70},
                      {INF, INF, INF, 0}
                    };
    cout << "The Minimum cost to reach station "
          << N << " is " << minCost(cost);
    return 0;
}