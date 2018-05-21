//1139. Nowa działka
//Kod zadania: MWPZ06X
#include <iostream>
#include <vector>
using namespace std;

int main() {
int t,num;
std::ios::sync_with_stdio(false);
	if(!(cin>>t))return 0;
	if(t<1||t>500) return 0;
	while(t--){
		cin>>num;
		if(num<1||num>1000)return 0;
		cout<<num*num<<endl;
	}

	return 0;
}
