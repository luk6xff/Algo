//4647. Telefony
//Kod zadania:  PTWPZ073



#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;



int phoneKeypadHashMap[256]={0};
static void doAlgorithm(vector<string> &dataset);

int main() {
	memset(phoneKeypadHashMap,0,256);
	for(int i ='A'; i<='Z';i++){
		
		unsigned char idx;
		if(i<'T'){
			idx=(((i-'A')/3)+2);
			phoneKeypadHashMap[i]=((idx<=7)?idx:7);
		}
		else{
			idx=(((i-'T')/3)+2+6);
			phoneKeypadHashMap[i]=((idx<=9)?idx:9);
		}
	}
	vector<string>  data;
 	int nrOfTests;
 	cin>>nrOfTests;
	if(nrOfTests<1||nrOfTests>20) return 0;
	
	while(nrOfTests--){
		string inStr;
		cin>>inStr;
		if(inStr.length()<4||inStr.length()>20) return 0;
		for(auto it =inStr.begin();it!=inStr.end();it++){
			if(*it<'A'||*it>'Z') return 0;
		}
		data.push_back(inStr);
	}
   	doAlgorithm(data);
   

return 0;
}



static void doAlgorithm(vector<string>& dataset){
    for(auto it =dataset.begin(); it!=dataset.end();it++){
        for(auto itStr =it->begin(); itStr!=it->end();itStr++){
            cout<<phoneKeypadHashMap[*itStr];
        }
        cout<<endl;
    }
	
}

