//1149. Konkurs pseudomatematyczny
//Kod zadania: MWPZ06H
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

void doAlgorithm(list<int> &dataSetList){
   int maxVal= *(std::max_element(dataSetList.begin(),dataSetList.end()));

  for(list<int>::iterator it = dataSetList.begin(); it!=dataSetList.end();it++){
   	
   	if(*it==maxVal){
   		cout<<(*it)<<" ";
   		dataSetList.erase(it);
   		it--;
   		}
   	}
    dataSetList.sort();
 if(!dataSetList.empty()){
  for(list<int>::iterator it = dataSetList.begin(); it!=dataSetList.end();it++){
   		cout<<(*it)<<" ";
   	}
   	cout<<endl;
 }
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	int D,N,data;
	cin>>D;
	if(D<1||D>500)return 0;
	
	while(D--){
		list<int> dataSetList;
		cin>>N;
		if(N<1||N>500)return 0;
		while(N--){
			
			cin>>data;
			if(data<0)return 0;
			dataSetList.push_back(data);
			
		}
		
		doAlgorithm(dataSetList);
	}
    
    return 0;
}



