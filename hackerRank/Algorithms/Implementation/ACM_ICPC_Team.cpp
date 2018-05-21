/********************************************/
/**ACM ICPC Team*******/
/********************************************/ 


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


static void solution(const vector<string>& data){
    
    if(data.size()==0 )
        return;
   int nrOfTopics = data.at(0).length();
   int nrOfGuys = data.size();
   
   vector<set<int> > zeroPlaces(nrOfGuys) ;
    
   for(int i=0;i<nrOfGuys;i++){
        for(int j=0;j<nrOfTopics;j++){
            if(data.at(i).at(j) =='0'){
                zeroPlaces[i].insert(j);
            }
        }
   }
    
   int maxSize= -1;
   int numOfTeamsCanAchieveMaxSize=1;
   for(int i=0;i<nrOfGuys-1;i++){       
        for(int j=i+1;j<nrOfGuys;j++){
            int tempMaxSize=  nrOfTopics- zeroPlaces.at(i).size();
            for(auto it=zeroPlaces.at(i).begin(); it!=zeroPlaces.at(i).end(); ++it){
                if(zeroPlaces[j].find(*it)==zeroPlaces[j].end()){
                    tempMaxSize++; 
                }
            }
            if(maxSize<tempMaxSize){
                maxSize=tempMaxSize;
                numOfTeamsCanAchieveMaxSize=1;
            }
            else if(maxSize==tempMaxSize){
                numOfTeamsCanAchieveMaxSize++;
            }
        }
   }   
    //cout<<"MAX_SZIE: "<<maxSize<<" NUM_OF_TEAMS_CAN_ACHIEVE_MAX_SIZE_OF_THE_TOPICS: "<<numOfTeamsCanAchieveMaxSize;
    cout<<maxSize<<'\n'<<numOfTeamsCanAchieveMaxSize<<'\n';
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }
    solution(topic);
    return 0;
}

