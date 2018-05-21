//575. Liczby znaczace
//Kod zadania: PZPI3

#include <bits/stdc++.h>
using namespace std;

const int maxSqrt = 32000;
static const bool* primes= NULL;
//* useful method */////////////////////
static bool* sieveOfEratosthenes(int n){
	bool *tab = new bool[n+1];
	memset(tab,true,(n+1)*sizeof(bool));
	tab[0]= false;
	tab[1]= false;
	for(int i =2;i<=sqrt(n);i++){   //sqrt(n) cuz of in the next for loop we start from x= i*i
		
		if(tab[i]==true)
			for(int x= i*i; x<=n;x+=i){
				tab[x]=false;
			}
	}
	/*
	for(auto i=2;i<=n;i++){
		if(tab[i]){
			cout<<i<<" "; //is prime
		}		
	}
	*/
	return tab;
}
///////////////////////////////////////////////////////////////////////////////



static double computeArithmeticMeanOfDivisorsOfNumber(int a){
	
	int i =2;
	double sum =0;
	while(i<=a/2){
		if(!(a%i))
			sum+=i;
		i++;
	}
//	cout<<sum/(i-2)<<" "<<i<<" --";
	if((i-2)<=0) return 0;
	return sum/(i-2);

}

static inline bool isPrime(int num)  // funkcja obliczający czy dana liczba jest pierwsza
{
 
   double sqrtOfNum=sqrt(num); 
   int i =2;
   bool res= true;
   if(num==0||num==1||num==4)
      res= false;
   else{
       while(i<=sqrtOfNum)
       {
          if(num%i==0)
            res= false;
            i++;
       }
    }
   return res;   
}




static void doAlgorithm(int a, int b){
	int nrOfMeaningfulNumber=0;
	/*
	if(!primes)return;
    
    for(int i =a;i<=b;i++){
    	
    	bool notPrimeFlag=false;
    	if(i<maxSqrt&&primes[i])
    		continue;
    	for(int j =2;j<=maxSqrt;j++){
    		if(primes[j]){
    			if((i%j)){
    			 notPrimeFlag =true;
    			 break;
    			}
    		}
    	}
    	
    	if(!notPrimeFlag)
    		continue;
    	if(computeArithmeticMeanOfDivisorsOfNumber(i)<(double)sqrt(i)){
    		nrOfMeaningfulNumber++;
    	}
    }
    */
    for(int i =a;i<=b;i++){
    	
    	if(isPrime(i)||i==0||i==1)
    		continue;
    	
    	
    	if(computeArithmeticMeanOfDivisorsOfNumber(i)<(double)sqrt(i)){
    		nrOfMeaningfulNumber++;
    	}
    }
    
    
    
    cout<<nrOfMeaningfulNumber<<'\n';
}





int main() {

	//primes= sieveOfEratosthenes(maxSqrt);
    int t,a,b;
    std::ios::sync_with_stdio(false);
	if(!(cin>>t))return 0;
	if(t>100000)return 0;
	while(t--){
		
		cin>>a>>b;
		if(a<1||a>b||a>1000000000||b>1000000000)return 0;
		doAlgorithm(a,b);
		
	}
	
	
	return 0;
}