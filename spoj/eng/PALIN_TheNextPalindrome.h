//The Next Palindrome 
//Kod zadania: PALIN


#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string palindr){
	
	int length= palindr.length();
	if(length==1)
		return true;
//	if(!(length%2)){ //odd
	for(int i =0;i<length/2;i++){
		
		if(palindr[i]!=palindr[palindr.length()-1-i])
			return false;
//	}
	return true;
	}
}



void doAlgorithm(string& str){
	
	if(str.length()==0){
		return ;
	}
	
	if(isPalindrome(str)){
		int length= str.length();
		//if(length%2){
			int i = 0;
			while(str[length/2-i]=='9'||str[length/2-i]==('9'+1)){
				str[length/2-i]='0';
				i++;
				if((length/2-i)<0){
					str.insert(0,"1");
					break;
				}
				else{
					str[length/2-i]=str[length/2-i]+1;
					if(str[length/2-i]<='9'&&str[length/2-i]>='1'){
						break;
					}
				}
			}
			for(int x =0;x<i;x++){
				if(str.length()%2){
					str[(str.length()/2+1)+x] = str[(str.length()/2-1)-x];
				}
				else{
					str[(str.length()/2)+x] = str[(str.length()/2-1)-x];
				}
			}

		cout<<str<<endl;
	}
		
	
	//cout<<isPalindrome(str)<<endl;
}


int main() {
    int t;  //nr of tests
    string pal;  //palindroms
    std::ios::sync_with_stdio(false);
	if(!(cin>>t))return 0;
	cin.ignore();
	while(t--){
		
		getline(cin,pal);
		if(pal.length()>1000000||pal.length()==0){
            return 0;
        }	
        
		doAlgorithm(pal);
		
	}
	return 0;
}