//https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    
    public:
        Graph(int n) : m_numOfVertexes(n) 
        {
            [this]()
            {
                for(size_t i = 0; i < m_numOfVertexes; ++i)
                {
                    m_vertices.push_back(std::move(set<int>()));
                }
            }();
        }
        ~Graph()
        {
        }
    
        void add_edge(int u, int v) 
        {
            m_vertices[u].insert(v);
            m_vertices[v].insert(u);
        }
    
        vector<int> shortest_reach(int startNode) 
        {
            vector<int> distances(m_numOfVertexes, -1);            
                queue<int> bfsQ;
                bfsQ.push(startNode);
                set<int> visited;
                bool doneFlag = false;
                distances[startNode] = 0; 
                
                while(!bfsQ.empty())
                {
                    int currentNode = bfsQ.front();
                    bfsQ.pop();
                    for(const auto& n: m_vertices[currentNode])
                    {
                        if(std::find(visited.begin(), visited.end(), n) == visited.end())
                        {
                           distances[n] = distances[currentNode]+6;
                           visited.insert(n);
                           bfsQ.push(n); 
                        }
                    }
                }            
            return distances;
            for (int i = 0; i < distances.size(); i++) 
            {
                if (i != startNode) 
                {
                    printf("%d ", distances[i]);
                }
            }
            printf("\n");
        }
    
    private:
        vector<set<int>> m_vertices;
        int m_numOfVertexes;
    
};

int main() {

    int queries;
    scanf("%d", &queries);       
    for (int t = 0; t < queries; t++) 
    {      
        int n, m;
        scanf("%d", &n);
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        scanf("%d", &m);
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d",&u);
            scanf("%d",&v);
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        scanf("%d", &startId);
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);
        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) 
            {
                printf("%d ", distances[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

