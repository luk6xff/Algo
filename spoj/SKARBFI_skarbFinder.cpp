//675. SkarbFinder
//Kod zadania: SKARBFINDER
// 0 - północ
// 1 - południe
// 2 - zachód
// 3 - wschód
//--etykieta poszukiwaczy skarbów tzn. 
//--tylko w kierunkach północ-południe, lub wschód-zachód)


#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

static void doAlgorithm(vector<pair<int,int> >&dataset);

typedef enum{
	North,
	South,
	West,
	East
}DIRECTION;


int main() {
	vector<vector<pair<int,int> > > wholeData;
 	int nrOfTests, nrOfHints, direction, nrOfSteps;
 	cin>>nrOfTests;
	if(nrOfTests<1||nrOfTests>50) return 0;
	
	while(nrOfTests--){
		
		cin>>nrOfHints;
		if(nrOfHints<0||nrOfHints>100000)return 0;
		
		vector<pair<int,int> > dataset;
		while(nrOfHints--){
	    	cin>>direction;
	    	cin>>nrOfSteps;
			if(direction<0||direction>3||nrOfSteps<1||nrOfSteps>10000)return 0;
		dataset.push_back(make_pair(direction,nrOfSteps));   
		}
		wholeData.push_back(dataset);
	}
   for(int i =0; i<wholeData.size();i++){
   		doAlgorithm(wholeData.at(i));
   }

return 0;
}



static void doAlgorithm(vector<pair<int,int> >& dataset){
	
	struct DirectionValues {
	
	DirectionValues(){
		N=0;
    	S=0;
    	W=0;
		E=0;	
	}	
		int N;
		int S;
		int W;
		int E;
	};
	DirectionValues	directVal;
	
	for(int i = 0; i<dataset.size(); i++){
	
		if(dataset.at(i).first==North)
			directVal.N+=dataset.at(i).second;
		else if(dataset.at(i).first==South)
			directVal.S+=dataset.at(i).second;
		else if(dataset.at(i).first==West)
			directVal.W+=dataset.at(i).second;
		else if(dataset.at(i).first==East)
			directVal.E+=dataset.at(i).second;
	}
	
	int WEsum =((directVal.W-directVal.E)<0)?East:West;
	int NSsum =((directVal.N-directVal.S)<0)?South:North;
	int WEval = abs(directVal.W-directVal.E);
	int NSval = abs(directVal.N-directVal.S);
	if(WEval==0&&NSval==0)cout<< "studnia"<<endl;
	else if(WEval!=0&&NSval!=0){
		cout<<NSsum<<" "<<NSval<<endl;
		cout<<WEsum<<" "<<WEval<<endl;
	}
	else if(WEval!=0){cout<<WEsum<<" "<<WEval<<endl;
	}
	else if(NSval!=0){cout<<NSsum<<" "<<NSval<<endl;}
	//cout<< "POINTNS "<< NSsum<<" "<<abs(directVal.W-directVal.E)<<endl<<"POINTWE "<<WEsum<<" "<<abs(directVal.N-directVal.S)<<endl;
	
}
