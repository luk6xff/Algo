//SHPATH
//Kod zadania: SHPATH - The Shortest Path

//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <iterator>     // std::istream_iterator
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
#include <numeric>
#include <chrono>
#include <list>

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

class AdjListNode{
	
	int v;
	int weight;
public:
	AdjListNode(int v, int w):v(v),weight(w){
		
	}
	int getV(){
		return v;
	} 
	int getWeight(){
		return weight;
	}
};

// Class to represent a graph using adjacency list representation
class WeightedGraph
{
    int v;    // No. of vertices'
 
    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;
	const int MAX= 99999999;
 
public:
    WeightedGraph(int v);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
 
    // Finds shortest paths from given source vertex
	void DijkstraFindShortestPath(int source, int destination);
 
};

WeightedGraph::WeightedGraph(int v){
	this->v= v;
	adj= new list<AdjListNode>[v];
}


void WeightedGraph::addEdge(int u, int v, int weight){
	
	adj[u].push_back( AdjListNode(v,weight) );
}


void WeightedGraph::DijkstraFindShortestPath(int source, int destination){
	typedef pair<int,int> pii;
	vector dist(v,MAX);
	dist[source]=0;
	//TODO

}



static void doAlgorithm(map<string, vector<pair<int,int>>>& dataMap,vector<pair<string, string>>& pathsVec){
	
	for (auto it=dataMap.begin(); it!=dataMap.end(); ++it){
		
		std::cout << it->first<< '\n';
		
		for (auto vecIt=it->second.begin(); vecIt!=it->second.end(); ++vecIt){
			
			std::cout<< vecIt->first << " " << vecIt->second << '\n';
		}
	}
	
	for (auto vecIt=pathsVec.begin(); vecIt!=pathsVec.end(); ++vecIt){
			
			std::cout<< vecIt->first << " " << vecIt->second << '\n';
	}
	
	
	
	WeightedGraph graph(dataMap.size());
	for(int i =0;i<dataMap.size();i++){
		for (auto vecIt=it->second.begin(); vecIt!=it->second.end(); ++vecIt){
			WeightedGraph.addEdge(i,vecIt->first,vecIt->second);
		}
	}
}


int main() {
    int s; //[the number of tests <= 10]
	int n; //[the number of cities <= 10000]
    string name; //city name
	int p; //the number of neighbours of city NAME
	int nr; // index of a city connected to NAME (the index of the first city is 1)
	int cost; //the transportation cost
	int r; //[the number of paths to find <= 100]
	string name1, name2; //NAME1 - source, NAME2 - destination
	
	map<string, vector<pair<int,int>>> vecCityNameNrCost;
	vector<pair<string, string>> pathsVec;
    std::ios::sync_with_stdio(false);
	//skipped checking input data
	if(!(cin>>s)) return 0;
	while(s--){
		std::cin>>n;
		if(n<=0||n>10000)
			return 0;
		while(n--){
		
			std::cin.ignore();
			std::getline(cin,name);
			std::cin>>p;
			vector<pair<int,int>>vec;
			while(p--){
				std::cin>>nr;
				std::cin>>cost;
				vec.push_back(make_pair(nr,cost));				
			}
			vecCityNameNrCost.insert(pair<string, vector<pair<int,int>>>(name,vec));
		}
		std::cin>>r; 
		if(r<=0||r>100)
			return 0;
			
		while(r--){
			istream_iterator<string> eos;         // end-of-stream iterator
		    istream_iterator<string> iit (std::cin);   // stdin iterator
			if (iit!=eos) name1=*iit;
			iit++;
			if (iit!=eos) name2=*iit;
			pathsVec.push_back(make_pair(name1,name2));
		}
		doAlgorithm(vecCityNameNrCost,pathsVec);
	}
		
	return 0;
}