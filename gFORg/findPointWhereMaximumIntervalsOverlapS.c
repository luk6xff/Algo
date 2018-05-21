/*
http://www.geeksforgeeks.org/find-the-point-where-maximum-intervals-overlap/    
SOLUTION: http://ideone.com/fY35vo
Consider a big party where a log register for guest’s entry and exit times is maintained. 
Find the time at which there are maximum guests in the party.
Note that entries in register are not in any order.
 
example
Input: arrl[] = {1, 2, 9, 5, 5}
       exit[] = {4, 5, 12, 9, 12}
First guest in array arrives at 1 and leaves at 4, 
second guest arrives at 2 and leaves at 5, and so on.
 
Output: 5
There are maximum 3 guests at time 5. 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
void doAlgorithm(vector<pair<int,int>>& data){
	std::unordered_map<int,int> result;
	for(int i=0;i<data.size();i++){
		for(int x=data.at(i).first;x<=data.at(i).second;x++){
			std::unordered_map<int,int>::const_iterator it=result.find(x);
			if (it == result.end() ){//key not found
				result.insert(std::make_pair(x,1));	
			}
  			else{
  				int temp= it->second;
  				result[x]=++temp;
  			}
		}
	}
	int time= 0;
	int nrOfGuests=0;
	for (auto& x:result){
    	//std::cout << x.first << ": " << x.second << std::endl;
    	if(x.second>nrOfGuests){
    		nrOfGuests= x.second;
    		time= x.first;
    	}
	}
    std::cout<<"There are maximum "<< nrOfGuests<<" guests at time "<<time<<endl;
}
 
 
 
int main() {
	int entry[] = {1, 2, 9, 5, 5};
    int exit[] = {4, 5, 12, 9, 12};
    vector<pair<int,int>> data; 
    for(int i=0; i<(sizeof(entry)/sizeof(entry[0]));i++){
    	data.push_back(make_pair(entry[i],exit[i]));
    }
    doAlgorithm(data);	
	return 0;
}