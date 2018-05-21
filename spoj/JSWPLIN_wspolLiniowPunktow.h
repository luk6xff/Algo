//1240. Współliniowość punktów
//Kod zadania: JWSPLIN
/*
[
	x1	y1	1
	x2	y2	1
	x3	y3	1
]
licze wyznacznik z takiej macierzy, jesli jest rowny 0, punkty sa wspolliniowe:

det(p1,p2,p3)= x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2
*/
#include <iostream>
#include <vector>
using namespace std;

void doAlgorithm(vector<int>& dataset){
   int det = dataset.at(0)*dataset.at(3)+dataset.at(2)*dataset.at(5)+dataset.at(4)*dataset.at(1)-dataset.at(0)*dataset.at(5)-dataset.at(2)*dataset.at(1)-dataset.at(4)*dataset.at(3);  
     if(det==0) cout<<"TAK"<<endl;
     else cout<<"NIE"<<endl;
}


int main()
{
	std::ios_base::sync_with_stdio(true);
	int t,data,pointCounter;
	cin>>t;
	if(t<2||t>100)return 0;
	while(t--){
		pointCounter=6;
		vector<int> dataset;
		while(pointCounter--){
			cin>>data;
			if(data<-1000||data>1000)
			return 0;
			dataset.push_back(data);
		}
		doAlgorithm(dataset);
	}
	
	return 0;
}



