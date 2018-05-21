//1242. Zliczacz liter
//Kod zadania: JZLICZ

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


static bool methodForSort(pair<char, int> a, pair<char, int> b ){
   	if(a.first>='a'&&a.first<='z'&&b.first>='A'&&b.first<='Z'){return true; }
   	else if(b.first>='a'&&b.first<='z'&&a.first>='A'&&a.first<='Z'){return false; }
   	if(a.first<b.first)return true;
   	else return false;
   }


static void doAlgorithm(string& text){
   vector<pair<char,int> > results;
  // cout<<text<<endl;
   for(string::iterator it=text.begin();it!=text.end();it++){
   	
   	if(*it>='a'&&*it<='z'||*it>='A'&&*it<='Z'){
   		if(results.empty()){
   			results.push_back(make_pair(*it,1));
   			}
   			
   		else{	
   			bool flagIsCharExist=false;
   			for(int i = 0; i<results.size();i++){
   				
   				if(*it==results.at(i).first){
   					results.at(i).second++;
   					flagIsCharExist=true;
   					break;
   				}
   			}
   			if(!flagIsCharExist)results.push_back(make_pair(*it,1));
   		 }
   		}
   }
   
  
   
   sort(results.begin(),results.end(),methodForSort);
   for(vector<pair<char, int> >::iterator it = results.begin();it!=results.end();it++){
   		cout<<it->first<<" "<<it->second<<endl;
   	}
}


int main()
{
	std::ios_base::sync_with_stdio(true);
	int N;
	string text;
	cin>>N;
	if(N>150||N<1)return 0;
	cin.ignore();
	while( N--){
     string temp;
	   getline(cin,temp);
	   text.append(temp);
	}
	doAlgorithm(text);
	return 0;
}



