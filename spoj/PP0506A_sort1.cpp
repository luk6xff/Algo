//663. Sort 1
//Kod zadania: PP0506A

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
	
	class Point{
		private:
	    string mName;
		int mX;
		int mY;
	    double mDistance;
		
		public: 
		Point(string &name, int x,int y ):mName(name),mX(x),mY(y){
			mDistance=sqrt((mX*mX)+(mY*mY));
		}
		
		double getDistance(void){
			return mDistance;
		} 
		int getX(void){
			return mX;
		} 
		int getY(void){
			return mY;
		} 
		string getName(void){
			return mName;
		} 
		bool operator==(const Point & point)const{
			if(this->mDistance == point.mDistance)
			return true;
			else return false;
		}
		bool operator<(const Point& point)const {
			if(this->mDistance < point.mDistance)
			return true;
			else return false;
		}
		bool operator>(const Point& point)const {
			if(this->mDistance > point.mDistance)
			return true;
			else return false;
		}
	};

void doAlgorithm(vector<pair<string,pair<int,int> > >& dataset);

int main() {
	vector<vector<pair<string,pair<int,int> > > > wholeData;
	int nrOfTestData,nrOfDataSets,cordinateX,cordinateY;
	string name;
	
	cin>>nrOfTestData;
	if(nrOfTestData<1)return 0;
	
	
	while(nrOfTestData--){
			cin>>nrOfDataSets;
			if(nrOfDataSets<1||nrOfDataSets>1000)return 0;
			vector<pair<string,pair<int,int> > > dataset;
		    while(nrOfDataSets--){
		    ;
		    	int i =10;
		        string name;
		
		        cin.ignore();
		    	getline(cin,name,' ');
		    	cin>>cordinateX;
		    	cin>>cordinateY;
		    	if(cordinateX<-1000||cordinateY>1000)return 0;
		    	dataset.push_back(make_pair(name,make_pair(cordinateX,cordinateY)));
		    }
		wholeData.push_back(dataset);
	}
	
	for(int i = 0; i<wholeData.size();i++){
		
		doAlgorithm(wholeData.at(i));
	}
	return 0;
}


void doAlgorithm(vector<pair<string,pair<int,int> > >& dataset){
	
	vector<class Point> points;
	
	for(int i = 0; i<dataset.size();i++){
		points.push_back(/*new*/ Point(dataset.at(i).first,dataset.at(i).second.first,dataset.at(i).second.second));
//	name =	dataset.at(i).first;
//	x= dataset.at(i).second.first;
//	y= dataset.at(i).second.second;
//	cout<<"DATASET size="<<dataset.size()<<" " <<name<<" "<< x<<" " << y<<" "<<endl;
	}
	
	sort(points.begin(),points.end()/*,greater<Point*>()*/);
	for(int i = 0; i<points.size();i++){
		cout<</*"DATASET size="<<points.size()<<" " <<*/points.at(i).getName()<<" "<<points.at(i).getX()<<" " << points.at(i).getY()/*<<"    "<<points.at(i).getDistance()*/<<endl;
	}
	
	//freeding
//	for(int i = 0; i<points.size();i++){
//		delete points.at(i);
//	}
}
