//1853. Formularz
//Kod zadania: KC005

#include <iostream>
#include <sstream>
using namespace std;


int doAlgorithm(string& data){
	int counter=0;
	//check name
    string::iterator nameIt= data.begin()+6;
    if(*nameIt<='Z'&&*nameIt>='A'){
	
		for(nameIt = data.begin()+7;;nameIt++,counter++){
			if(*nameIt==';')break;
			if(*nameIt<'a'||*nameIt>'z'||counter>=9) return 0;
		}
	}
	else return 0;
	
	//check surname
	nameIt+=12;
	counter=0;
	if(*nameIt<='Z'&&*nameIt>='A'){

		for(nameIt = nameIt+1;;nameIt++,counter++){
			
			if(*nameIt==';')break;
			if(*nameIt<'a'||*nameIt>'z'||counter>=19) return 1;
		}
	}
	else return 1;
	
	//check date--
	//check year
	nameIt+=12;
	int rrrr,mm,dd;  //year/month/day
	string temp;
		for(;*nameIt!='-'&&nameIt!=data.end();nameIt++){
			if(*nameIt<'0'||*nameIt>'9')return 2;
			 temp.push_back(*nameIt);
		}
		std::istringstream ss;
		ss.str(temp);
		ss >> rrrr;
		if(rrrr<1900||rrrr>2000)return 2;
		//check MOnth
		nameIt++;
		temp.clear();
		for(;*nameIt!='-'&&nameIt!=data.end();nameIt++){
			if(*nameIt<'0'||*nameIt>'9')return 2;
			 temp.push_back(*nameIt);
		}
	    std::istringstream sss;
		sss.str(temp);
		sss >> mm;
		if(mm<1||mm>12)return 2;
	   //check Day
		nameIt++;
		temp.clear();
		for(;nameIt!=data.end();nameIt++){
			if(*nameIt<'0'||*nameIt>'9')return 2;
			 temp.push_back(*nameIt);
		}
	    std::istringstream sD;
		sD.str(temp);
		sD >> dd;
		if(mm==2&&(dd<1||dd>29))return 2;
		if((mm==4||mm==6||mm==9||mm==11)&&(dd<1||dd>29))return 2;
		if(dd<1||dd>31)return 2;
	
   return 3;
}





int main() {
	string dataset;

while(getline(cin,dataset)){
	
	cout<<doAlgorithm(dataset)<<endl;
	dataset.clear();
	}
	return 0;
}
