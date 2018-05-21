//4138. Harry and big doughnuts
//Kod zadania: DOUGHNUT


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int main() {
	
	ios_base::sync_with_stdio(0);
	
	
    int nrOfTests;
    int c,k,w;
    cin>>nrOfTests;
    if(nrOfTests<1||nrOfTests>100) return 0;
	while(nrOfTests--){
		cin>>c>>k>>w;
		if(c<1||c>100||k<1||k>100||w<1||w>100)
			return 0;
	   if((c*w)<=k)cout<<"yes"<<endl;
	   else cout<<"no"<<endl;
	}
	

	return 0;
}
