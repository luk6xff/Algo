//1042. Transponowanie macierzy
//Kod zadania: TRN
#include <iostream>
#include <vector>
using namespace std;

void doAlgorithm(vector<vector<int> >& matrix){
	vector<vector<int> > matrixTrn(matrix.at(0).size(), vector<int>(matrix.size()));
	
	for(int m= 0;m< matrix.at(0).size();m++)	{
		for(int n= 0;n< matrix.size();n++){
	     	matrixTrn.at(m).at(n)=matrix.at(n).at(m);//push_back(matrix.at(n).at(m));
	   		}
		}
	//cout<<matrixTrn.size()<<" "<<matrixTrn.at(0).size()<<" " <<matrix.size()<<" "<<matrix.at(0).size()<<endl;
	for(int i= 0;i< matrixTrn.size();i++){
	   for(int j= 0;j< matrixTrn.at(i).size();j++)	{
	   	
	   	cout<<matrixTrn.at(i).at(j)<<" ";
	   }
		cout<<endl;
	}
	// cout<<endl;
	
	//debug
	/*
	for(int i= 0;i< matrix.size();i++){
	   for(int j= 0;j< matrix.at(i).size();j++)	{
	   	
	   	cout<<matrix.at(i).at(j)<<" ";
	   }
		cout<<endl;
	}
	 cout<<endl;
	 */
}


int main() {
int m,n,num;
std::ios::sync_with_stdio(false);
	if(!(cin>>m>>n)) return 0;
	if(m<1||m>200||n<1||n>200)return 0;
    vector<vector<int> > matrix(m,vector<int>(n));
	for(int i=0;i<m;i++){
		for(int j =0;j<n;j++){
			
			if(!(cin>>num))return 0;
			matrix.at(i).at(j)=num;//push_back(num);
		}
	}
	


		doAlgorithm(matrix);
		
	

	return 0;
}
