//442. Searching the Graph
//Kod zadania: TDBFS
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
/////////////////////////////////////////////////
static void doAlgorithm(Graph& graph,int startVertex, int bfsORdfs){
	
	if(bfsORdfs==1)
    	graph.bfs(startVertex);
    else
    	graph.dfs(startVertex);
   	cout<<"\n";
}


int main() {
    int t,n,i,m,val,v;
    int nrOfGraph=0;
    std::ios::sync_with_stdio(false);
	if(!(cin>>t))return 0;
	while(t--){
		cin>>n;
		Graph graph(n);
		
		while(n--){
			cin>>i>>m;
			while(m--){
				cin>>val;
				graph.addEdge(i-1,val-1);
			}
		}
		cout<<"graph "<<++nrOfGraph<<"\n"; 
		while(1){
			cin>>v>>i;
			if(v==0&&i==0)
				break;
			doAlgorithm(graph,v-1, i);
		}
	}
	return 0;
}
