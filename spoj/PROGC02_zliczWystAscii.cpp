//2016. Zliczanie wystąpień (kody ASCII)
//Kod zadania: PROGC02



#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

static bool isGreaterAsciiCode(pair<unsigned char,int> first,pair<unsigned char,int> second){
	
	if(first.first<second.first) return true;
    return false;
}


static void doAlgorithm(string &dataset){
	
	vector<pair<unsigned char,int> > res;	
	bool newAsciiCode=true;
	for(string::iterator it =dataset.begin(); it!=dataset.end();it++){
		for(int i =0; i<res.size();i++ ){
			if(static_cast<unsigned char>(*it)==res.at(i).first){
				res.at(i).second++;
				newAsciiCode=false;
				break;
			}
			newAsciiCode=true;
		}
		if(newAsciiCode){
		  res.push_back(make_pair(static_cast<unsigned char>(*it),1));
		 // cout<<"HERE: "<<static_cast<unsigned char>(*it)<<endl;
		}
	}
	for(int i =0; i<res.size();i++ ){
	
	sort(res.begin(),res.end(),isGreaterAsciiCode);
	cout<<static_cast<int>(res.at(i).first)<<" "<<res.at(i).second<<endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	string data;
	string temp;

	while(getline(cin,temp)){
		temp+='\n';  //do not forget to add, getline cuts it
		data.append(temp);
	}
		/*
		int zn;
			while((zn = getchar()) != EOF){
			data+=(unsigned char)zn;	
		}
		*/
	doAlgorithm(data);
return 0;
}
