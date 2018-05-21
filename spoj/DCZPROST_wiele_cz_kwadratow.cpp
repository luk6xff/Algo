//4256. Wiele czerwonych kwadratów
//Kod zadania: DCZPROST


#include <iostream>
using namespace std;

static void doAlgorithm(int XLD,int YLD,int XPG, int YPG){
	
 long long sum=0;
 for(int i = YLD; i<YPG;i++){
 	 if(i%2){
 	 	if(XPG>i&&XLD<=i){
 	 		sum+=(i-XLD)+1;
 	 	}
 	 	else if(XLD>i){
 	 		
 	 	}
 	 	else if(XPG<=i){
 	 		sum+=XPG-XLD;
 	 	}
 	 }
 }
  for(int i = XLD; i<XPG;i++){
 	 if(i%2){
 	 	if(YPG>i&&YLD<=i){
 	 		sum+=(i-YLD);
 	 	}
 	 	else if(YPG<=i){
 	 		sum+=YPG-YLD;
 	 	}
 	 }	 
 }
 cout<<sum<<endl;




}



int main() {
	ios_base::sync_with_stdio(false);
 int XLD,YLD,XPG,YPG;
 
 cin>>XLD>>YLD>>XPG>>YPG;
 if(XLD<0||XLD>1000000||XPG<0||XPG>1000000||YLD<0||YLD>1000000||YPG<0||YPG>1000000)
 	return 0;
 	
 	doAlgorithm(XLD,YLD,XPG,YPG);
 
	return 0;
}

