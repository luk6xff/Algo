//STRING MERGE Kod zadania: PP0504B

#include <iostream>
#include <cstring>

using namespace std;

#define T_SIZE 1001

char* string_merge(char *, char *);

int main(){
  int t,n; 
  char S1[T_SIZE], S2[T_SIZE], *S;

  cin >> t; /* wczytaj liczbę testów */
  cin.getline(S1,T_SIZE); 
  while(t){ 
    cin.getline(S1,T_SIZE,' ');
    cin.getline(S2,T_SIZE);      
    S=string_merge(S1,S2);
    cout << S << endl;
    delete[] S;
    t--;   
  } 
  return 0;
}

char* string_merge(char *str1, char *str2){
  if(str1==NULL || str2==NULL)return NULL;
char *newStr=NULL;	
int shorterLength= strlen(str1)<strlen(str2)?strlen(str1):strlen(str2);
	newStr= new char[shorterLength*2+1];
	//cout<<"ADDR: "<<newStr<<endl;

	for(int i=0; i<shorterLength;i++){
		*(newStr++)	= str1[i];
		*(newStr++)	= str2[i];
	}
	*newStr=NULL;
	//	cout<<"ADDR: "<<*(newStr-(shorterLength*2))<<endl;
	return (newStr-(shorterLength*2));
}

/*
char* string_merge(char *t1,char *t2)
{
    char *wsk;
    int x=strlen(t1),y=strlen(t2),ile;
    if(x>y)
        ile=2*y;
    else
        ile=2*x;
    wsk=new char[ile];
    for(int i=0,j=0;i<ile;i++,j+=2)
    {
        wsk[j]=t1[i];
        wsk[j+1]=t2[i];
    }
    return(wsk);
}
*/