//1056. Tabelki liczb
//Kod zadania: PP0602B
#include <iostream>
#include <vector>
using namespace std;
 


void doAlgorithm(int** dataset,int nrOfRows, int nrOfColumns){

/*
 int tempBuf[nrOfRows*nrOfColumns];
 
 int ptr;
 for(int i= 0; i<nrOfColumns;i++){
 	tempBuf[i]	= dataset[0][i];
 	ptr=i;
 }
 for(int i= 1; i<nrOfRows;i++){
 	tempBuf[ptr+i]	= dataset[i][nrOfColumns-1];
 }
 
 ptr+=nrOfRows;
 for(int i= nrOfColumns-2; i>=0;i--){
 	tempBuf[ptr+nrOfColumns-2-i]	= dataset[nrOfRows-1][i];
 }
 
 ptr+=nrOfColumns-1;
 for(int i=nrOfRows-2; i>0;i--){
 	tempBuf[ptr+nrOfRows-2-i]	= dataset[i][0];
 }

*/
/*
	//debug
	for(int i =0;i<nrOfRows;i++){
			for(int j =0;j<nrOfColumns;j++){
				cout<<dataset[i][j]<<" ";
		}
		cout<<endl;
	}
    //debug
	for(int i =0;i<nrOfRows*nrOfColumns;i++){
		cout<<tempBuf[i]<<" ";
	}
	cout<<endl;
	
	// debug
	//debug
		cout<<endl;
		*/
	for(int i =0;i<nrOfRows;i++){
			for(int j =0;j<nrOfColumns;j++){
				

				if(i==0){
				 	if(j==nrOfColumns-1){
				 		cout<<dataset[i+1][j]<<" ";
					 }
				 	else cout<<dataset[i][j+1]<<" ";
				}
				else if(i==nrOfRows-1){
					if(j==0){
					   cout<<dataset[i-1][j]<<" ";	
					}
					
					else  cout<<dataset[i][j-1]<<" ";
					
				}
				else if(j==0&&i>0&&i<nrOfRows-1){
					cout<<dataset[i-1][j]<<" ";
				}
				
				else if(j==nrOfColumns-1&&i>0&&i<nrOfRows-1){
					
					cout<<dataset[i+1][j]<<" ";
				}
				else cout<<dataset[i][j]<<" ";
				
		}
		cout<<endl;
	}
}


int main() {
int t,l,k;
std::ios::sync_with_stdio(false);
	if(!(cin>>t))return 0;
	while(t--){
		
		cin>>l>>k;
		if(k>100||l<3)return 0;
		int** tab = new int*[l];
		for(int i = 0; i < l; ++i) {
    		tab[i] = new int[k];
		}
		
		
		for(int i =0;i<l;i++){
			
			for(int j =0;j<k;j++){
				cin>>tab[i][j];
			}
		}
			doAlgorithm(tab,l,k);
			for(int i = 0; i < l; ++i) {
    			delete[] tab[i];
			}
			delete[] tab;
		}

	return 0;
}
