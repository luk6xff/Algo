//http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/
/*

Given an input string and a dictionary of words, 
find out if the input string can be segmented into a space-separated sequence 
of dictionary words. See following examples for more details.
This is a famous Google interview question, 
also being asked by many other ompanies now a days.
 
*/

///////////////////////////////////////////////1 version////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

static bool dictionaryContains( const string& word){
	
	string dictionary[]= {"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","like","ice","cream"};
                       
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for(int i=0;i<size;i++){
        if(dictionary[i].compare(word)==0)
            return true;
    }
    return false;
}


bool doAlgorithm(const string& word){
	
	int size = word.length();
    int tab[ size+1];
    memset(tab,0,sizeof(tab));
    for(int i =1; i< size;i++){
        
        if(dictionaryContains(word.substr(0,i))){
        	for(int x=0+1;x<=i;x++){
        		tab[x]=1;
        	}
        }
        if(tab[i]){
	    	for(int j=i+1; j<= size;j++){
	    		if(dictionaryContains(word.substr(i,j-i))){
	  				//cout<<word.substr(i,j);
	    			for(int x=i;x<=j;x++){
	    				tab[x]=1;
	    			}
	    		}
	    	}
        }
    }
    for(int x=1;x<=size;x++){
    	if(tab[x]==0)
    		return false;
        //cout<<tab[x]<<" ";
        //cout<<endl;
    }
    return true;
    
}





int main()
{

    
    
    doAlgorithm("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    doAlgorithm("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    doAlgorithm("")? cout <<"Yes\n": cout << "No\n";
    doAlgorithm("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    doAlgorithm("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    doAlgorithm("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    return 0;
}

// OUTPUT:
/*
    Yes
    Yes
    Yes
    Yes
    Yes
    No
*/

