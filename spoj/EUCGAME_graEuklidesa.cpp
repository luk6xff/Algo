//804. Gra Euklidesa
//Kod zadania: EUCGAME

#include <iostream>
#include <vector>
using namespace std;

static void doAlgorithm(pair<int,int>& coin){
	
	if(coin.first==coin.second){
		
	cout<< coin.first+coin.second<<endl; return;	
	}
	int lowerNum = (coin.first<coin.second)?coin.first:coin.second;
	int biggerNum = (coin.first>coin.second)?coin.first:coin.second;
	if(!(biggerNum%lowerNum)){
		cout<<(lowerNum*2)<<endl; return;
	}
	while(1){
		biggerNum-=lowerNum;
		//cout<<biggerNum<<" "<<lowerNum<<" "<<endl;
		if(biggerNum==lowerNum) break;
		int temp=biggerNum;
		biggerNum = (lowerNum>biggerNum)?lowerNum:biggerNum;
		lowerNum = (lowerNum<temp)?lowerNum:temp;
	}
	cout<<(biggerNum+lowerNum)<<endl;
}


int main() {
	vector<pair<int,int> > dataset;
	
	int nrOfGames,playerA,playerB;
    cin>>nrOfGames;
    if(nrOfGames<1||nrOfGames>10) return 0;
    
    while(nrOfGames--){
    	cin>>playerA;
    	cin>>playerB;
    	if(playerA<1||playerA>1000000000||playerB<1||playerB>1000000000)return 0;
    	
    	dataset.push_back(make_pair(playerA,playerB));
    	
    	
    }
    
    for(int i= 0;i<dataset.size();i++){
    	doAlgorithm(dataset.at(i));
    }
    
    
	return 0;
}
