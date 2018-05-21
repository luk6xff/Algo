//2 cyfry silni
//Kod zadania: FCTRL3

#include <iostream>
#include <vector>
using namespace std;

int computeFactorial(int n){
	int res=0;
	if(n<=1) res = 1;
	
	else{
		res=1;
		for(int i=1;i<=n;i++){
			res = res*i;
		}
		
	}
	return res;
	}
	
int computeFactorialRecursive(int n){
	
	if(n==0) 
		return 1;
	
	else{
		return n* computeFactorialRecursive(n-1);
		}
	}
	
	
typedef struct{
	int nrOfTens;
	int nrOfOnes;
}TensAndOnes;

TensAndOnes getTensAndOnesOfnumber(int n){
	
	TensAndOnes temp;
	
	temp.nrOfTens= (n / 10) % 10;
	temp.nrOfOnes=n%10;
	return temp;
	
	}


int main() {
	int nrOfTests;
	int data;
	TensAndOnes tAndOnes;
	
	vector<int> dataVector;
	
	cin>>nrOfTests;
	if(nrOfTests>30||nrOfTests<1)return 0;
	
	while(nrOfTests--){
		
	
	cin>>data;
	if(data<0||data>1000000000) return 0; 
		dataVector.push_back(data);
		
	}

	for(vector<int>::iterator it =dataVector.begin(); it!=dataVector.end(); it++){
		
		if(*it>9){
		
		tAndOnes.nrOfTens=0;	
		tAndOnes.nrOfOnes= 0;	
			
		}
		
		else
		tAndOnes= getTensAndOnesOfnumber(/*computeFactorial*/computeFactorialRecursive(*it));

	    cout<<tAndOnes.nrOfTens<<" "<<tAndOnes.nrOfOnes<<"\n";
		
	}
	
	
	return 0;
}
