#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
 


int main() {
    long long int T,N,M,Ai;
	if(!(cin>>T))return 0;
	while(T--){
 
		cin>>N>>M;
		if(N>100000||N<1||M>100000||M<1)return 0;
		unordered_map<long long int,bool> dataMap;
		while(N--){
			scanf("%lld",&Ai);
			if(Ai>1000000000000||Ai<0)return 0;
			dataMap[Ai]=true;
		}
		while(M--){
			scanf("%lld",&Ai);
			//if(Ai>1000000000000||Ai<0)return 0;
			if(dataMap[Ai])
				printf("YES\n");
			else{
				printf("NO\n");
				dataMap[Ai]=true;;
			}
		}

	}
	return 0;
}