

//Graph 
// Graph is a data structure that consists of following two components:
// 1. A finite set of vertices also called as nodes.
// 2. A finite set of ordered pair of the form (u, v) called as edge. 
// The pair is ordered because (u, v) is not same as (v, u) in case 
// of directed graph(di-graph). The pair of form (u, v) indicates 
// that there is an edge from vertex u to vertex v. The edges may contain weight/value/cost.

// Graphs are used to represent many real life applications: 
// Graphs are used to represent networks. The networks may include paths 
// in a city or telephone network or circuit network. Graphs are also used 
// in social networks like linkedIn, facebook


#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <list>
#include <queue>
#include <complex>
#include <numeric>

using namespace std;
///////////////////////////////////////NOT WEIGHTED GRAPH IMPLEMENTATION////////////////////////
class Graph{
	
	int v; //nr of vertices
	list<int> *adj; //pointer to an array containing adjacency lists

public:
 Graph(int v);
 void addEdge(int v, int val);// function to add an edge to graph
 void bfs(int s);  // prints BFS traversal from a given source s
 
 void dfsUtil(int v, bool visited[]);
 void dfs(int s);// prints DFS traversal from a given source s
};

Graph::Graph(int v){
	this->v=v;
	adj = new list<int>[this->v];
}

void Graph::addEdge(int v, int val){
	adj[v].push_back(val);	
	
}

void Graph::bfs(int s){
    // Mark all the vertices as not visited
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
 
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s+1 << " ";
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }	
}

void Graph::dfsUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v+1 << " ";
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            dfsUtil(*i, visited);
}
 
// uses recursive DFSUtil()
void Graph::dfs(int s)
{
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;
    dfsUtil(s, visited);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////WEIGHTED GRAPH IMPLEMENTATION////////////////////////


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
	
	adj[u].push_back(AdjListNode(v,weight) );
}


void WeightedGraph::DijkstraFindShortestPath(int source, int destination){
	typedef pair<int,int> pii;
	vector dist(v,MAX);
	dist[source]=0;
	//TODO

}
