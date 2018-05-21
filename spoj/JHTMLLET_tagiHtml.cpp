//1289. Tagi HTML
//Kod zadania: JHTMLLET

#include <iostream>
using namespace std;


static bool doAlgorithm(string& text){
 //cout<<text<<endl;
 
 if(!((text.at(0)=='<'||(text.at(0)=='<'&&text.at(1)=='/'))&&text.at(text.length()-1)=='>')) return 0;
 
 bool isTagOpen=false;
 for(string::iterator it =text.begin();it!=text.end();it++){
 	if(isTagOpen&&(*it!='>')){
 		
 		if(*it>='a'&&*it<='z') *it=*it-32;
 	}
 	else isTagOpen=false;
 	