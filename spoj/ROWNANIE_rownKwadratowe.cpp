//969. Równanie kwadratowe
//Kod zadania: ROWNANIE

#include <iostream>
#include <vector>
using namespace std;


void doAlgorithm(double *ptr){
	
if(ptr==NULL)return;

double a= ptr[0];
double b= ptr[1];
double c= ptr[2];

double delta = b*b - (4*a*c);
int nrOfRoots; 
if(delta ==0 ) nrOfRoots=1;
else if(delta<0) nrOfRoots=0;
else nrOfRoots=2;

cout<<nrOfRoots<<endl;
}

int main() {	
	vector<double*> data;
	double num;


    while(1/*!cin.eof()*/){
    	
    	double * ptr = new double[3];
    
    if(!(cin>>num)) break;
    else ptr[0] =num;
    
      if(!(cin>>num)) break;
    else ptr[1] =num;
    
      if(!(cin>>num)) break;
    else ptr[2] =num;
    /*
    	cin>>ptr[0];
    	cin>>*(ptr+1);
    	cin>>*(ptr+2);
    	*/
        data.push_back(ptr);
    }
    
    for(int i =0 ; i<(data.size());i++){
    	
    	doAlgorithm(data.at(i));
    	delete[] data.at(i);
    }
	return 0;
}


