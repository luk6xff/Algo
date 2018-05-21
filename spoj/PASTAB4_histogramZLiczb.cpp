//3328. Histogram z liczb
//Kod zadania: PASTAB4


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

static int roundx(double d)
{
  return ((d + 0.5));
}

struct myCompareClass {
  bool operator() (pair<int,int> x, pair<int,int> y ) { return x.second < y.second; }
} myCompareObj;

static void doAlgorithm(vector<int>& dataset){
  const int	SZEROKOSC = 30;
  const int MIN = -10;
  const int MAX =10;
  vector<pair<int,int> > data;
  for(int i =MIN;  i<=MAX;i++){
  	data.push_back(make_pair(i,0));
  }
  //cout<<dataset.at(i)<<endl;
  
  for(int i =0; i<dataset.size();i++){
      data.at(dataset.at(i)+10).second++;
  }
  pair<int,int> maxPair = *std::max_element(data.begin(),data.end(),myCompareObj);
  int maxVal = maxPair.second;


  for(int i = 0; i<data.size(); i++){
  	if(data.at(i).first ==-10)cout<<" ";
  	else if(data.at(i).first<0||data.at(i).first==10)cout<<"  ";
  	else cout<<"   ";
  	cout<<data.at(i).first<<":|";
  	int nrOfStars= roundx((double)(data.at(i).second*SZEROKOSC)/maxVal);
  	for(int j = 0; j<SZEROKOSC; j++){
  		if(j<nrOfStars){
  			cout<<"*";
  		}
  		else cout<<" ";
  	}
  	cout<<"|"<<endl;
  	
  }


}


int main() {
	
	ios_base::sync_with_stdio(0);
	
	vector<int> dataset;
    int x;
	while((cin>>x)){
		if(x<-10||x>10)return 0;
		dataset.push_back(x);
	}
    doAlgorithm(dataset);
	return 0;
}
