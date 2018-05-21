//977. Tablica
//Kod zadania: TABLICA

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {	
	vector<int> data;
	int num;


    while(1/*!cin.eof()*/){
    	
    
    if(!(cin>>num)) break;
    else data.push_back(num);
    }

 std::reverse(data.begin(),data.end());
 
 for(vector<int>::iterator it = data.begin();it!=data.end();it++){
 	
 	cout<<*it<<" ";
 	
 }
 cout<<endl;
	return 0;
}



