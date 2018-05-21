//4138.PRINT - Prime Intervals
//Kod zadania: PRINT 


#include <bits/stdc++.h>
using namespace std;


static void printSieveOfEratosthenes(int L, int U){
	
	bool tab[U];
	memset(tab,true,sizeof(tab));
	
	for(int i =2;i<=sqrt(U);i++){   //sqrt(n) cuz of in the next for loop we start from x= i*i
		
		if(tab[i]==true)
			for(int x= i*i; x<=U;x+=i){
				tab[x]=false;
			}
	}
	for(int i=L;i<=U;i++){
		if(tab[i]){
			cout<<i<<"\n";

		}		
	}
	cout<<"\n";
}


void doAlgorithm(int L, int U){
	//if(L>10000||L<0) //check data correctness
    //  return 0;
	printSieveOfEratosthenes(L, U);
}


int main() {
    int T;  //nr of tests
    int L,U; 
    long int nrOfCoins; // nr of coins with each monster
    std::ios::sync_with_stdio(false);
	if(!(cin>>T))return 0;
	while(T--){
		
		cin>>L>>U;
		doAlgorithm( L, U);
	}
	return 0;
}