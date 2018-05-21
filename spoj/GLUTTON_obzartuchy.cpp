//626. Obżartuchy
//Kod zadania: GLUTTON
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
void doAlgorithm(vector<int> data);

int main() {
vector<vector<int> > inData; 
int nrOfData;
int N,M; 
int time;

cin>>nrOfData;
if(nrOfData<1)return 0;
//cout<<"NR OF DATA"<<nrOfData<<endl;
while(nrOfData--){
	vector<int> temp;
	cin>>N;
	if(N<1||N>10000)return 0;
	cin>>M;
	if(M<1||M>1000000000)return 0;
	temp.push_back(N);
	temp.push_back(M);
	
	while(N--){
	cin>>time;
	if(time>100000)return 0;
	temp.push_back(time);
	}
	inData.push_back(temp);
}

 for(int i =0; i < inData.size(); i++){
 	doAlgorithm(inData.at(i));
 }
	
	return 0;
}

void doAlgorithm(vector<int> data){
	const int secsInHour =86400;
	int nrOfEaters= data.at(0);
	int nrOfCakesInBox= data.at(1);
	int res=0;
	for(int i =0;i<nrOfEaters;i++){
		
		res+=(secsInHour/data.at(2+i));
	}
	int finalRes;
	if(!(res%nrOfCakesInBox))
	finalRes=(res/nrOfCakesInBox);
	else finalRes=(res/nrOfCakesInBox)+1;
	cout<<finalRes<<endl;
}
