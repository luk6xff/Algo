//http://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
//https://ideone.com/fqGls6

#include <bits/stdc++.h>
using namespace std;

void doAlgorithm(vector<unsigned int>& arrival,vector<unsigned int>& departure){
	
    if((arrival.size()!=departure.size()) || arrival.size()==0||departure.size()==0)
        return;
    int hashMap[2400];
    for(int i=0;i<arrival.size();i++){
        hashMap[arrival[i]]=1;
    }
    for(int i=0;i<departure.size();i++){
        hashMap[departure[i]]=0;

    }
    arrival.insert(arrival.end(),departure.begin(),departure.end());
	
    sort(arrival.begin(),arrival.end());
    int nrOfPlatforms=1;
    int count=1;
    for(int i =1; i<arrival.size();i++){
        if(hashMap[arrival[i]]==1&&hashMap[arrival[i-1]]==1){
           count++;
           if(count>nrOfPlatforms){
                nrOfPlatforms+=1;  
           }
        }
        else count=1;
    }
    cout<<"Minimum Number of Platforms Required = "<<nrOfPlatforms<<endl;
}


int main() {

    vector<unsigned int> arr= {900, 940, 950, 1100, 1500, 1800};
    vector<unsigned int> dep= {910, 1200, 1120, 1130, 1900, 2000}; 
    
    doAlgorithm(arr, dep);
		
	return 0;
}