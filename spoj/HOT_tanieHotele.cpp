//4344. Tanie hotele
//Kod zadania: HOT


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct myCompareClass {
  bool operator() (pair<int,int> x, pair<int,int> y ) { return x.second < y.second; }
} myCompareObj;


#if 0
static void doAlgorithm(int routeLength, vector<pair<int,int> >& hotels){
	/*cout<<"ROUTE LENGTH:"<<routeLength<<endl;
	for(int i =0;i<hotels.size();i++){
		cout<<"HOTEL nr:"<<i<<" "<<", L:"<<hotels.at(i).first<<", Price:"<<hotels.at(i).second<<endl;	
	}
	*/
	int price=0;
	int nrOfNights=  routeLength/800;
	int range=0;
	for(int i = 0;i<nrOfNights;i++){
		int lastRange= range;
		for(range =lastRange;;range++){ 
			//cout<<hotels.at(range).first<<endl;
			//cout<<"RANGECOUNT:"<<range<<endl;
			if(range==hotels.size()-1||(hotels.at(range).first>((i+1)*800))){
				//cout<<"RANGE:"<<range<<endl;
				break;
			}
		}
		pair<int,int> minPrice = *std::min_element(hotels.begin()+lastRange,hotels.begin()+range,myCompareObj);
		//cout<<"MIN_PRICE"<<minPrice.first<<" "<<minPrice.second<<endl;
		price+=minPrice.second;
	}
	cout<<price<<endl;
}
#endif

static void doAlgorithm(int routeLength, vector<pair<int,int> >& hotels){
	/*cout<<"ROUTE LENGTH:"<<routeLength<<endl;
	for(int i =0;i<hotels.size();i++){
		cout<<"HOTEL nr:"<<i<<" "<<", L:"<<hotels.at(i).first<<", Price:"<<hotels.at(i).second<<endl;	
	}
	*/
	int price=0;
	int nrOfNights=  routeLength/800;
	
	
	

}



int main() {
	ios_base::sync_with_stdio(false);
	int d, h;
	cin>>d>>h;
	if(d>16000||d<1||h>1000||h<1)
 		return 0;
 	vector<pair<int,int> > hotels;
 	while(h--){
 		int length,price;
 		cin>>length>>price;
 		if(length>d||price>1000||length<0||price<0)
 			return 0;
 		hotels.push_back(make_pair(length,price));
 	}
 	
 	doAlgorithm(d,hotels);
 
	return 0;
}


