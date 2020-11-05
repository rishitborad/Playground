//
//  graph.cpp
//  Practice
//
//  Created by Dexter's Lab on 11/3/20.
//

#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

class Graph
{
private:
    list<int> *adj;
    int V;      // Number of vertices
public:
    Graph(){}
    Graph(int V):V(V)
    {
        adj = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void printGraph()
    {
        for(int i = 0 ; i < V; i++)
        {
            for(auto j = adj[i].begin(); j != adj[i].end(); j++)
            {
                printf("%d --> %d\r\n", i, *j);
            }
        }
    }
};

//======================================================================//

//vector<int> vec[5];
//addEdge(vec, 0, 2);
//addEdge(vec, 1, 2);
//addEdge(vec, 1, 3);
//addEdge(vec, 2, 3);
//addEdge(vec, 2, 4);
//addEdge(vec, 3, 4);
//printGraph(vec, 5);

void addEdge(vector<int> adj[], int i, int j)
{
    adj[i].push_back(j);
    adj[j].push_back(i);
}


void printGraph(vector<int> graph[], int V)
{
    for(size_t i = 0; i < V; i++)
    {
        for(size_t j = 0; j < graph[i].size(); j++)
        {
            printf("%d --> %d\r\n", (int)i, graph[i][j]);
        }
    }
}

//======================================================================//

// __LOCAL_MAIN__
void run_graph()
{
    Graph G(5);
    G.addEdge(0, 2);
    G.addEdge(1, 2);
    G.addEdge(3, 1);
    G.addEdge(2, 3);
    G.addEdge(2, 4);
    G.addEdge(4, 3);
    G.printGraph();
}

