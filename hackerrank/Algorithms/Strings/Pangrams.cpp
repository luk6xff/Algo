/********************************************/
/**Pangrams*******/
/********************************************/ 
 
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
 
int main() {
    unsigned char sizeOfTheAlphabetArr= 128;
    char alphabet[sizeOfTheAlphabetArr];
    memset(alphabet,'1',sizeOfTheAlphabetArr);
    
    string data;
    getline(std::cin,data);    
    for(auto ch:data){
        if(ch>='A'&&ch<='Z'){
            if(alphabet[ch]=='1'){
                alphabet[ch]='0'; 
                alphabet[ch+0x20]='0';
            }
        }
        else{
            if(alphabet[ch]=='1'){
                alphabet[ch]='0'; 
                alphabet[ch-0x20]='0';
            }
        }
    }
    for(int i=0;i<='Z'-'A';i++){
        //cout<<"++ "<<alphabet[i+'A']<<"-- "<<alphabet[i+'A'+0x20];
        if(alphabet[i+'A']!='0'||alphabet[i+'A'+0x20]!='0'){
            cout<<"not pangram"<<endl;
            return 0;
        }
      
    }
    cout<<"pangram"<<endl;
    return 0;
}
 