//Repr liczb typu float Kod zadania: PP0504D

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
void printfloat(float);
int main() {
vector<float> inData; 
float nrOfData; 
float data;

cin>>nrOfData;
if(nrOfData<1)return 0;
while(nrOfData--){
	
	cin>>data;
	
	inData.push_back(data);
}

	
 for(int i =0; i < inData.size(); i++){
 	printfloat(	inData.at(i));
 	
 }
	
	return 0;
}

void printfloat(float data){
	const unsigned char *tab = reinterpret_cast<const unsigned char*>(&data);
	printf("%x %x %x %x\n", tab[3], tab[2], tab[1], tab[0]);
}
