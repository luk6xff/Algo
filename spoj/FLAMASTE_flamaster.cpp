//flamaster
//Kod zadania: FLAMASTE 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
void shortenString(string& strToBeShorten){
char previousChar='z';
int strLength= strToBeShorten.length();
bool twoTimesTheSameLatterOccured = false;
int startOfTheLetter =0;
int counter =0;
vector<pair<int,int> > startOfRepetitionAndLength;
for(int i = 0; i<strLength; i++){if(twoTimesTheSameLatterOccured == true){
		if(previousChar== strToBeShorten.at(i)){if(startOfTheLetter==0){startOfTheLetter =i;}counter++;if(i==strLength-1){	startOfRepetitionAndLength.push_back(make_pair(startOfTheLetter-1,counter+1));}}else {if(startOfTheLetter!=0){startOfRepetitionAndLength.push_back(make_pair(startOfTheLetter-1,counter+1 ));	}startOfTheLetter =0;counter=0;twoTimesTheSameLatterOccured = false;}}
	else if(previousChar== strToBeShorten.at(i))
	   twoTimesTheSameLatterOccured = true;
	previousChar= strToBeShorten.at(i);}int startPosDifferenceAfterErasing = 0;
for(int i = 0; i<startOfRepetitionAndLength.size(); i++){
strToBeShorten.erase(startOfRepetitionAndLength.at(i).first-startPosDifferenceAfterErasing,startOfRepetitionAndLength.at(i).second);
ostringstream ss;
ss<<startOfRepetitionAndLength.at(i).second+1;
string temp=ss.str();
strToBeShorten.insert(startOfRepetitionAndLength.at(i).first-startPosDifferenceAfterErasing,temp);
startPosDifferenceAfterErasing+= startOfRepetitionAndLength.at(i).second-temp.length(); //length Of the vector
}}
int main() {
int nrOfTests;vector<string > dataVector;	cin>>nrOfTests;cin.ignore();
	if(nrOfTests>50||nrOfTests<1)return 0;for(int i =0; i<nrOfTests; i++){
	string str;	getline(cin,str);
	if(str.length()>200||str.length()<1) return 0;
	for ( std::string::iterator it=str.begin(); it!=str.end(); ++it){if(*it<'A'||*it>'Z') return 0;}	
	dataVector.push_back(str);}
	for(vector<string>::iterator it =dataVector.begin(); it!=dataVector.end(); it++){shortenString(*it);cout<<*it<<"\n";}
	return 0;}
