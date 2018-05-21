//1145. Imieniny
//Kod zadania: MWPZ06D

#include <iostream>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	int nrOfTests,nrOfGuys,nrOfCandies;
	
	cin>> nrOfTests;
	if(nrOfTests<1||nrOfTests>500)return 0;
	while(nrOfTests--){
		bool res;
	cin>>nrOfGuys>>nrOfCandies;
	if(nrOfGuys<1||nrOfGuys>1000000000||nrOfCandies<1||nrOfCandies>1000000000) return 0;
	
	if(((nrOfGuys-1)>nrOfCandies)&&nrOfCandies!=1) res= true;
	else if(nrOfGuys==1)res= true;
   else if(nrOfGuys==2&&nrOfCandies==1)res= false;
	else if(nrOfCandies==1)res= true;
	else if(((nrOfCandies)%(nrOfGuys-1))) res=true;
	else res= false;
		
		if(res==true)cout<<"TAK"<<"\n";
		else cout<<"NIE"<<"\n";
		
		
	}
	return 0;
}
