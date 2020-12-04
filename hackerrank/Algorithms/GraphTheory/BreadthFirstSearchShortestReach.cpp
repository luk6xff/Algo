/********************************************/
/**Breadth First Search: Shortest Reach******/
/********************************************/ 


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Graph{
    private:
        int v; //number of vertices
        list<int> *adj; //adjacency lists 
    
    public:
    
        Graph(int v){
            this->v=v;
            this->adj = new list<int>[v];
        }
    
        void addEdge(int v, int w){
            if(v>=this->v||w>=this->v){
                return;
            }
            adj[v].push_back(w);  //add w to v's list
            adj[w].push_back(v);  //add v to w's list
        }
    
        int getV(void){
            return v;
        }
    
        list<int>& getAdjacentVertices(int v){
            return adj[v];
        }
};


class BreadthFirstSearch{


    
  public:
    BreadthFirstSearch(Graph& graph, int s){
        marked= new bool[graph.getV()];
        edgeTo= new int[graph.getV()];
        this->s =s;
        bfs(graph, s);
    } 

    ~BreadthFirstSearch(){
        delete[] marked;
        delete[] edgeTo;       
    }
    
    
    bool hasPathTo(int v){
        return marked[v];
    }
    
    int getLastEdgeTo(int v){
        return edgeTo[v];
    }
    
  private:
    
    int s;          //source    
    bool *marked;   // is a shortest path to this vertex known
    int *edgeTo;    //last vertex on known path to this vertex    
      
    void bfs(Graph& graph, int s){ //source
        for(int i = 0; i < graph.getV(); i++)
            marked[i] = false;
        list<int> queue;         //a queue for BFS
        queue.push_back(s);
        marked[s]=true;
        
        while(!queue.empty()){
            int v= queue.front();           //remove next vertex from the queue
            queue.pop_front();
            for(auto i =graph.getAdjacentVertices(v).begin();i!=graph.getAdjacentVertices(v).end();++i){
                //cout<<"V= "<<v<<"   i= "<<*i<<endl;
                if(!marked[*i]){            // for every unmarked adjacent vertex
                    marked[*i]=true;        //mark it because path is known
                    queue.push_back(*i);    //add it ti the queue
                    edgeTo[*i]=v;           //save last edge on the shortest path
                }
            }       
        }
    }
    

    
};

static void solution( Graph& graph,int s){
    BreadthFirstSearch *bfs = new BreadthFirstSearch(graph,s);
    for(int i=0 ;i<graph.getV();i++){
        if(s!=i){
            if(bfs->hasPathTo(i)){
                int pathLength=1;
                int lastEdge=i;
                while(1){
                    lastEdge=bfs->getLastEdgeTo(lastEdge);
                    if(lastEdge==s)
                        break;
                    pathLength++;
                }
                cout<<pathLength*6<<" ";
            }
            else
                cout<<"-1"<<" ";
        }
    }
    cout<<endl;
}

int main(){
    int T; //num of tests
    int N;
    int M;
    int s;
    cin >>T;
    while(T--){
        cin>>N>>M;
        Graph graph(N);
        for(int i=0;i<M;i++){
            int v,w;
            cin>>v>>w;   
            graph.addEdge(v-1,w-1);  //-1 cuz we start from 0
        }         
        cin>>s;
        solution(graph,s-1);
    }
    return 0;
}