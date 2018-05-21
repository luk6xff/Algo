//http://www.geeksforgeeks.org/a-boolean-matrix-question/
 
//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>
 
using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef string STR;
 
 
#define V(x) vector<x>
#define P(a,b) pair<a,b>
 
 
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))
 
 
static void doAlgorithm(vector<vector<bool>>& matrix){
 
 int nrOfRows= matrix.size();   // real nr is -1
 int nrOfCols =  matrix.at(0).size(); //real nr is -1 
 
 if(!nrOfRows||!nrOfCols)
 return; 
 bool row[nrOfRows]; //temp tables
 bool col[nrOfCols];
 memset(row,0,sizeof(row));
 memset(col,0,sizeof(col));
 
 int mRow=0;
    for(auto itRow =matrix.begin();itRow!=matrix.end();++itRow){
     int mCol=0;
     for(auto itCol =itRow->begin();itCol!=itRow->end() ;++itCol){
 if(*itCol==1){
 row[mRow]=1;
 col[mCol]=1;
 }
 mCol++;
     }
     mRow++;
    }
    
    for(int i=0; i<nrOfRows;i++ ){ //row
     if(row[i]==1){
  for(int j=0; j<nrOfCols;j++ ) 
 matrix.at(i).at(j)=1;
 
     }
    }
    
    for(int i=0; i<nrOfCols;i++ ){//col
     if(col[i]==1){
  for(int j=0; j<nrOfRows;j++ ) 
 matrix.at(j).at(i)=1;
     }
    }
}
 
 
static void printMatrix(vector<vector<bool>>& matrix){
 
    for(auto itRow =matrix.begin();itRow!=matrix.end();++itRow){
     for(auto itCol =itRow->begin();itCol!=itRow->end() ;++itCol){
 cout<<*itCol<<" ";
     }
     cout<<endl;
    }
}
 
int main() {
 vector<vector<bool>> matrix = {{1, 0, 0, 1},{0, 0, 1, 0},{0, 0, 0, 0}};
 
 cout<<"INPUT MATRIX: "<<endl;
 printMatrix(matrix);
 
 doAlgorithm(matrix);
 
 cout<<"MATRIX AFTER MODIFICATION: "<<endl;
 printMatrix(matrix);
 
 return 0;
}
