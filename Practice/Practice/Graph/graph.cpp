//
//  graph.cpp
//  Practice
//
//  Created by Dexter's Lab on 11/3/20.
//

#include <stdio.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include "common.hpp"
using namespace std;

//======================================================================//

//INPIT
//    Graph G(5);
//    G.addEdge(0, 2);
//    G.addEdge(1, 2);
//    G.addEdge(3, 1);
//    G.addEdge(2, 3);
//    G.addEdge(2, 4);
//    G.addEdge(4, 3);
//    G.printGraph();
//    G.BFS(4);
//    printf("\r\n");
//    G.DFS(0);
//    printf("\r\n");
//    G.BFS_recursive(3);
//    printf("\r\n");
//    G.DFS_recursive(4);
//    printf("\r\n");
//    vector<pair<int, int>>times = G.DFS_ArrivalDepartureTimes();
//    for(int i = 0 ; i < times.size();i++){
//        printf("V:%d, startTime: %d, endTime: %d\r\n", i, times[i].first, times[i].second);
//    }

class Graph{
  
private:
    int V;
    list<int>* adj;
public:
    Graph(){}
    Graph(int V): V(V){
        adj = new list<int>[V];
    }
    void addEdge(int src, int dest){
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    void printGraph(){
        for(int i = 0 ; i < V; i++){
            printf("Vertex %d : ", i);
            for(auto j = adj[i].begin(); j != adj[i].end(); j++){
                printf("%d-->", *j);
            }
            printf("\r\n");
        }
    }
    
    void BFS(int V){
        vector<bool>visited(5,false);
        queue<int> q;
        visited[V] = true;
        q.push(V);
        
        while(!q.empty()){
            int elem = q.front();
            q.pop();
            printf("%d ",elem);
            for(auto i = adj[elem].begin(); i != adj[elem].end(); i++){
                if(!visited[*i]){
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
    }
    
    void BFS_recursive_util(queue<int>& q, vector<bool>&visited){
        if(q.empty())
            return;
        int elem = q.front();
        q.pop();
        printf("%d",elem);
        for(auto i = adj[elem].begin(); i != adj[elem].end(); i++){
            if(!visited[*i]){
                visited[*i] = true;
                q.push(*i);
            }
        }
        BFS_recursive_util(q, visited);
    }
    void BFS_recursive(int startNode){
        vector<bool>visited(V, false);
        queue<int>q;
        for(int i = startNode ; i < startNode+V; i++){
            if(visited[i%V] == false){
                q.push(i%V);
                visited[i%V] = true;
                BFS_recursive_util(q, visited);
            }
        }
    }
    
    void DFS(int V){
        vector<bool>visited(5,false);
        stack<int> stk;
        visited[V] = true;
        stk.push(V);
        
        while(!stk.empty()){
            int elem = stk.top();
            stk.pop();
            printf("%d ",elem);
            for(auto i = adj[elem].begin(); i != adj[elem].end(); i++){
                if(!visited[*i]){
                    visited[*i] = true;
                    stk.push(*i);
                }
            }
        }
    }
    
    void DFS_recursive_util(int startNode, vector<bool>& visited){
        visited[startNode] = true;
        printf("%d",startNode);
        for(auto i = adj[startNode].begin(); i != adj[startNode].end(); i++){
            if(!visited[*i]){
                DFS_recursive_util(*i, visited);
            }
        }
    }
    void DFS_recursive(int startNode){
        vector<bool>visited(V,false);
        for(int i = startNode; i < startNode+V; i++){
            if(!visited[i%V]){
                DFS_recursive_util(i, visited);
            }
        }
    }
    
    void DFS_ArrivalDepartureTimes_util(int currntV, int& timer, vector<bool>&visited, vector<pair<int, int>>& times){
        visited[currntV] = true;
        for(auto j = adj[currntV].begin(); j != adj[currntV].end(); j++){
            if(!visited[*j]){
                int startTime = timer++;
                DFS_ArrivalDepartureTimes_util(*j, timer, visited, times);
                int endTime = timer++;
                times[*j] = {startTime,endTime};
            }
        }
    }
    vector<pair<int, int>> DFS_ArrivalDepartureTimes(){
        vector<bool>visited(V,false);
        vector<pair<int, int>> times(V);
        int timer= 0;
        for(int i = 0 ; i < V; i++){
            if(!visited[i]){
                int startTime = timer++;
                DFS_ArrivalDepartureTimes_util(i, timer, visited, times);
                int endTime = timer++;
                times[i] = {startTime,endTime};
            }
        }
        return times;
    }
};

//======================================================================//
//INPUT
//    Graph1 G(9);
//    G.addEdges(1,2);
//    G.addEdges(3,2);
//    G.addEdges(3,4);
//    G.addEdges(4,6);
//    G.addEdges(5,7);
//    G.addEdges(5,9);
//    G.addEdges(8,9);
//    G.addEdges(2,8);
//    G.addEdges(7,9);
//    G.printGraph(1);
//    if(G.BFS_bipartite(1)){
//        printf("Graph is Bipartite\r\n");
//    }
//    else{
//        printf("Graph is not Bipartite\r\n");
//    }
//    if(G.DFS_bipartite(1)){
//        printf("Graph is Bipartite\r\n");
//    }
//    else{
//        printf("Graph is not Bipartite\r\n");
//    }


typedef enum color{
    NONE = 0,
    RED = 1,
    GREEN = 2,
} color_t;

class Graph1{
private:
    int V;
    list<int>* adj;
public:
    Graph1(){}
    Graph1(int v):V(v+1){
        adj = new list<int>[V];
    }
    void addEdges(int src, int dest){
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    void printGraph(int startIdx){
        for(int i = startIdx; i < startIdx+V; i++){
            int idx = i;
            printf("Vertex %d : ", idx);
            for(auto j = adj[idx].begin(); j != adj[idx].end(); j++){
                printf("%d-->", *j);
            }
            printf("\r\n");
        }
    }
    bool BFS_bipartite_util(vector<bool>&visited, queue<int>&q, vector<color_t>&vColors){
        if(q.empty())
            return true;
        int elem = q.front();
        q.pop();
        printf("%d: ",elem);
        
        for(auto i = adj[elem].begin(); i != adj[elem].end(); i++){
            printf("%d ", *i);
            if(!visited[*i]){
                q.push(*i);
                visited[elem] = true;
                vColors[*i] = (vColors[elem] == GREEN) ? RED : GREEN;
            }else if(vColors[*i] == vColors[elem]){
                return false;
            }
            
        }
        printf("\r\n");
        return BFS_bipartite_util(visited, q, vColors);
    }
    
    bool BFS_bipartite(int startV){
        queue<int>q;
        vector<color_t>vColors(V,NONE);
        vector<bool>visited(V,false);
        for(int i=startV; i < V; i++){
            int idx = i;
            if(!visited[idx]){
                q.push(idx);
                vColors[idx] = GREEN;
                visited[idx] = true;
                return BFS_bipartite_util(visited, q, vColors);
            }
        }
        return true;
    }
    
    
    bool DFS_bipartite_util(int elem, vector<bool> &visited, vector<color_t>& vColor){
        printf("%d: ",elem);
        for(auto i = adj[elem].begin(); i != adj[elem].end(); i++){
            printf("%d ", *i);
            if(!visited[*i]){
                visited[*i] = true;
                vColor[*i] = (vColor[elem] == GREEN) ? RED : GREEN;
                printf("\r\n");
                return DFS_bipartite_util(*i, visited, vColor);
            }else if(vColor[elem] == vColor[*i]){
                return false;
            }
        }
        return true;
    }
    
    bool DFS_bipartite(int startV){
        vector<color_t>vColors(V,NONE);
        vector<bool>visited(V,false);
        bool res = true;
        for(int i = startV; i < V; i++){
            if(!visited[i]){
                visited[i] = true;
                vColors[i] = GREEN;
                res &= DFS_bipartite_util(i, visited, vColors);
            }
        }
        return res;
    }
};

//======================================================================//
//INPUT
//    vector<Edge> edges = {{7,1},{7,0},{5,1},{1,4},{1,6},{1,2},{3,4},{3,0},{0,6}};
//    TopoSort G(8);
//    G.addEdges(edges);
//    common_print_1D_vector(G.getTopologicalSort());

struct Edge{
    int src;
    int dest;
};

class TopoSort{
private:
    int V;
    list<int>* adj;
public:
    TopoSort(){}
    TopoSort(int v):V(v){
        adj = new list<int>[V];
    }
    void addEdges(vector<Edge>&edges){
        for(Edge edge: edges){
            adj[edge.src].push_back(edge.dest);
        }
    }
    
    void calculateInEdges(vector<int>& inedges){
        for(int i = 0 ; i < V; i++){
            for(auto j = adj[i].begin(); j != adj[i].end(); j++){
                inedges[*j]++;
            }
        }
    }
    
    vector<int> getTopologicalSort(){
        vector<int>inEdges(V,0);
        vector<int>sortedVertices;
        queue<int>q;
        calculateInEdges(inEdges);
        
        for(int i = 0 ; i < V; i++){
            if(inEdges[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            sortedVertices.push_back(v);
            for(auto i = adj[v].begin(); i != adj[v].end(); i++){
                if(--inEdges[*i] == 0){
                    q.push(*i);
                }
            }
        }
        return sortedVertices;
    }
    
};

//======================================================================//
//  INPUT:
//    unordered_map<int, int>snake,ladder;
//    // insert ladders into the map
//    ladder[1] = 38;
//    ladder[4] = 14;
//    ladder[9] = 31;
//    ladder[21] = 42;
//    ladder[28] = 84;
//    ladder[51] = 67;
//    ladder[72] = 91;
//    ladder[80] = 99;
//
//    // insert snakes into the map
//    snake[17] = 7;
//    snake[54] = 34;
//    snake[62] = 19;
//    snake[64] = 60;
//    snake[87] = 36;
//    snake[93] = 73;
//    snake[95] = 75;
//    snake[98] = 79;
//    snakeLadder s = snakeLadder(snake,ladder);
//    printf("MinThrows are: %d\r\n",s.FindMinThrows());
struct Node{
    int idx;
    int minPath;
};

class snakeLadder{
private:
    int V;
    list<int>* adj;
public:
    snakeLadder(){}
    int FindMinThrows(){
        queue<Node>q;
        Node ans;
        vector<bool>visited(V,false);
        q.push({0,0});
        visited[0] = true;
        while(!q.empty()){
            Node v = q.front();
            q.pop();
            if(v.idx == 100){
                ans = v;
                break;
            }
            for(auto i = adj[v.idx].begin(); i != adj[v.idx].end(); i++){
                if(!visited[*i]){
                    visited[*i] = true;
                    q.push({*i,v.minPath+1});
                }
            }
        }
        return ans.minPath;
    }
    
    snakeLadder(unordered_map<int, int>&snake, unordered_map<int, int>&ladder){
        V = 100+1;  // 100 numbers + 0 to begin with
        adj = new list<int>[V];
        
        int src = 0;
        int dest = 0;
        
        for(int i = 0; i <= 100; i++){
            src = i;
            for(int j = 1; j < 6 && ((i+j) <= 100); j++){
                dest = (snake[i+j] != 0 || ladder[i+j] != 0) ? (snake[i+j] + ladder[i+j]) : (i+j);
                adj[src].push_back(dest);
            }
        }
    }
};

//======================================================================//
// INPUT
//    vector<Edge>edges = {{7,1},{7,0},{5,1},{3,4},{3,0},{1,4},{1,2},{1,6},{0,6}};
//    KahnsTopoSort k(8);
//    k.addEdges(edges);
//    printf("Khan'sTopoSort\r\n");
//    common_print_1D_vector(k.sortGraph());
class KahnsTopoSort{
private:
    int V;
    list<int>* adj;
public:
    KahnsTopoSort(){}
    KahnsTopoSort(int v):V(v){
        adj = new list<int>[V];
    }
    void addEdges(vector<Edge>&edges){
        for(auto &e : edges){
            adj[e.src].push_back(e.dest);
        }
    }
    void countIndegree(vector<int>&indegree){
        for(int i = 0 ; i < V; i++){
            for(auto j = adj[i].begin(); j != adj[i].end(); j++){
                indegree[*j]++;
            }
        }
    }
    vector<int> sortGraph(){
        vector<int>indegree(V,0);
        vector<bool>visited(V,false);
        queue<int>q;
        vector<int>answer;
        countIndegree(indegree);
        for(int i=0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            answer.push_back(v);
            for(auto i = adj[v].begin(); i != adj[v].end(); i++){
                if(--indegree[*i] == 0){
                    q.push(*i);
                }
            }
        }
        return answer;
    }
};


//======================================================================//
//input:
//    vector<Edge>edges = {{0,1},{1,2},{3,1},{2,0},{3,2}};
//    GraphMatrix g(4);
//    g.addEdges(edges);
//    g.printMatrix();
//    if(g.hasSimplePath(0, 3)){
//        printf("HasSimplePath\r\n");
//    }
class GraphMatrix{
private:
    int V;
    vector<vector<int>> matrix;
public:
    GraphMatrix(){}
    GraphMatrix(int v):V(v){
        matrix = vector<vector<int>>(V, vector<int>(V,0));
    }
    void addEdges(vector<Edge>&edges){
        for(auto e: edges){
            matrix[e.src][e.dest] = 1;
        }
    }
    void printMatrix(){
        for(int i = 0 ; i < V; i++){
            for(int j = 0 ; j < V; j++){
                printf("%d ", matrix[i][j]);
            }
            printf("\r\n");
        }
    }
    
    int hasSimplePath_DFS(int v, vector<int>&visited, int d){
        if(v == d){
            return 1;
        }
        for(int i = 0 ; i < V; i++){
            if(matrix[v][i] == 1 && !visited[i]){
                visited[i] = 1;
                if(hasSimplePath_DFS(i, visited, d)){
                    return 1;
                }
            }
        }
        return 0;
    }
    
    int hasSimplePath(int s, int d){
        vector<int>visited(V, 0);
        if(s == d){
            return 1;
        }
        visited[s] = 1;
        for(int i = 0 ; i < V; i++){
            if(matrix[s][i] == 1 && !visited[i]){
                visited[i] = 1;
                if(hasSimplePath_DFS(i, visited, d)){
                    return 1;
                }
            }
        }
        return 0;
    }
};

//======================================================================//

//INPUT:
//vector<Edge>edges = {{0,1},{1,2},{3,1},{2,0},{3,2}};
//UD_GraphCycle g(4,edges);
//if(g.haveCycle_DFS(0)){
//    printf("has a cycle\r\n");
//}

struct Node_vp{
    int idx;
    int parent;
};

class UD_GraphCycle{
private:
    int V;
    list<int>* adj;
public:
    UD_GraphCycle(){}
    UD_GraphCycle(int v, vector<Edge>edges):V(v){
        adj = new list<int>[V];
        
        for(int i = 0 ; i < (int)edges.size(); i++){
            adj[edges[i].src].push_back(edges[i].dest);
            adj[edges[i].dest].push_back(edges[i].src);
        }
    }
    
    bool haveCycle_DFS_util(vector<bool>&visited, Node_vp v, vector<Node_vp>&parent){
        printf("%d %d\r\n",v.idx, v.parent);
        for(auto i = adj[v.idx].begin(); i != adj[v.idx].end(); i++){
            if(!visited[*i]){
                visited[*i] = true;
                parent[*i] = {*i,v.idx};
                if(haveCycle_DFS_util(visited, parent[*i], parent)){
                    return true;
                }
            }else if(parent[v.idx].parent != parent[*i].parent){
                return true;
            }
        }
        return false;
    }
    
    bool haveCycle_DFS(int startV){
        vector<bool>visited(V,false);
        vector<Node_vp>parent(V,{0,-1});
        visited[startV] = true;
        parent[startV] = {startV,-1};
        return haveCycle_DFS_util(visited, parent[startV], parent);
    }
};

//======================================================================//
//INPUT:
//    vector<Edge>edges = {{0,1},{1,2},{3,1},{2,0},{3,2},{1,4},{2,4}};
//    D_GraphCycle g(5,edges);
//    printf("Total Paths are %d\r\n",g.count_paths_DFS(0,4));
//    printf("Total Paths are %d\r\n",g.count_paths_BFS(0,4));

class D_GraphCycle{
private:
    int V;
    list<int>* adj;
public:
    D_GraphCycle(){}
    D_GraphCycle(int v, vector<Edge>edges):V(v){
        adj = new list<int>[V];
        
        for(int i = 0 ; i < (int)edges.size(); i++){
            adj[edges[i].src].push_back(edges[i].dest);
        }
    }
    
    int haveCycle_DFS_util(vector<bool>&visited, int v, int dest){
        printf("%d, dest%d\r\n",v,dest);
        if(v == dest){
            visited[dest] = false;
            return 1;
        }
        int paths = 0;
        for(auto i = adj[v].begin(); i != adj[v].end(); i++){
            if(!visited[*i]){
                visited[*i] = true;
                paths+= haveCycle_DFS_util(visited, *i, dest);
            }
        }
        return paths;
    }
    
    int count_paths_DFS(int src, int dest){
        vector<bool>visited(V,false);
        visited[src] = true;
        return haveCycle_DFS_util(visited, src, dest);
    }
    
    int count_paths_BFS_util(vector<bool>&visited, queue<int>q, int dest){
        int count = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            printf("V:%d\r\n",v);
            if(v == dest){
                visited[v]=false;
                count++;
            }
            for(auto i = adj[v].begin(); i!= adj[v].end(); i++){
                if(!visited[*i]){
                    q.push(*i);
                }
            }
        }
        return count;
    }
    int count_paths_BFS(int src, int dest){
        vector<bool>visited(V,false);
        queue<int>q;
        visited[src] = true;
        q.push(src);
        return count_paths_BFS_util(visited, q, dest);
    }
};
//======================================================================//
//INPUT
//    vector<Edge>edges = {{0,1},{0,2},{2,1},{1,3},{3,2},{4,2},{3,4},{3,5},{5,4}};
//    Graph_ShortestPath g(6, edges);
//    printf("Shortest path is %d\r\n", g.findShortestPath(0, 5));
struct DP{
    int distance;
    int parent;
};

class Graph_ShortestPath{
private:
    int V;
    list<int>* adj;
public:
    Graph_ShortestPath(){}
    Graph_ShortestPath(int v, vector<Edge>&edges): V(v){
        adj = new list<int>[V];
        for(int i = 0 ; i < (int)edges.size(); i++){
            adj[edges[i].src].push_back(edges[i].dest);
        }
    }
    
    void DFS(queue<int>&q, vector<DP>& info){
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto i = adj[v].begin(); i != adj[v].end(); i++){
                if(info[*i].distance == -1){
                    q.push(*i);
                    info[*i].distance = info[v].distance+1;
                    info[*i].parent = v;
                }
            }
        }
    }
    
    int findShortestPath(int src, int dest){
        queue<int>q;
        vector<DP>info(V);
        for(int i = 0 ; i < V; i++){
            info[i].distance = -1;
            info[i].parent = -1;
        }
        info[src].distance = 0;
        q.push(src);
        DFS(q, info);
        for(int i = 0 ; i < info.size();i++){
            printf("%d %d %d\r\n",i,info[i].distance, info[i].parent);
        }
        return info[dest].distance;
    }
};

//======================================================================//
//INTPUT
//vector<weightedEdge>negativeWeightEdges = {{0,1,1},{0,2,1},{1,3,1},{3,2,1},{4,2,1},{3,4,3},{3,5,-5},{5,4,1},{2,1,1}};
//Bellman g(6, negativeWeightEdges);
//printf("Shortest path is %d\r\n", g.shortestPath(0, 4));

struct weightedEdge{
    int src;
    int dest;
    int w;
};

class Bellman{
private:
    int V;
    list<pair<int,int>>* adj;
public:
    Bellman(){}
    Bellman(int v, vector<weightedEdge>edges):V(v){
        adj = new list<pair<int, int>>[V];
        for(int i = 0 ; i < (int)edges.size(); i++){
            adj[edges[i].src].push_back({edges[i].dest,edges[i].w});
        }
    }
    
    struct compare{
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second < p2.second;
        }
    };
    
    
    bool BFS(queue<pair<int, int>>&q, vector<DP>&dp, vector<bool>&inQ, vector<int>&counter){
        while(!q.empty()){
            pair<int, int> v = q.front();
            q.pop();
            inQ[v.first] = false;
            printf("%d %d %d\r\n",v.first,dp[v.first].distance,dp[v.first].parent);
            for(auto i = adj[v.first].begin(); i != adj[v.first].end(); i++){
                int newDist = v.second + i->second;
                int idx = i->first;
                if(dp[idx].distance > newDist){
                    dp[idx].distance = newDist;
                    dp[idx].parent = v.first;
                    if(!inQ[idx]){
                        q.push({idx, newDist});
                        counter[idx]++;
                        if(counter[idx] > V){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
   
    int shortestPath(int src, int dest){
        vector<bool>inQ(V,false);
        vector<int>counter(V,0);
        queue<pair<int, int>> q;
        vector<DP> dp(V,{INT_MAX, -1});
        dp[src].distance = 0;
        q.push({src,0});
        inQ[src] = true;
        counter[src]++;
        if(!BFS(q,dp,inQ,counter)){
            printf("Found negative cycle");
            return dp[dest].distance;
        }
        for(int i = 0 ; i < dp.size(); i++){
            printf("%d %d %d\r\n", i , dp[i].distance, dp[i].parent);
        }
        return dp[dest].distance;
    }
};


//======================================================================//
// Dijkstra woint work if there is a negative cycle. Bellman ford will take care of negative cycle
//INPUT
//vector<weightedEdge>nonNegativeWeightEdges = {{0,1,1},{0,2,1},{1,3,1},{3,2,1},{4,2,1},{3,4,3},{3,5,5},{5,4,1},{2,1,1}};
//Dijkstra d(6, nonNegativeWeightEdges);
//printf("Dijkstra path %d\r\n", d.shortestPath(0,4));

class Dijkstra{
private:
    int V;
    list<pair<int,int>>* adj;
public:
    Dijkstra(){}
    Dijkstra(int v, vector<weightedEdge>edges):V(v){
        adj = new list<pair<int, int>>[V];
        for(int i = 0 ; i < (int)edges.size(); i++){
            adj[edges[i].src].push_back({edges[i].dest,edges[i].w});
        }
    }
    
    struct compare{
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second < p2.second;
        }
    };
    
    
    void BFS(priority_queue<pair<int, int>, vector<pair<int, int>>, compare>&q, vector<DP>&dp){
        while(!q.empty()){
            pair<int, int> v = q.top();
            q.pop();
            printf("%d %d %d\r\n",v.first,dp[v.first].distance,dp[v.first].parent);
            for(auto i = adj[v.first].begin(); i != adj[v.first].end(); i++){
                int newDist = v.second + i->second;
                int idx = i->first;
                if(dp[idx].distance > newDist){
                    dp[idx].distance = newDist;
                    dp[idx].parent = v.first;
                    q.push({idx, newDist});
                }
            }
        }
    }
   
    int shortestPath(int src, int dest){
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
        vector<DP> dp(V,{INT_MAX, -1});
        dp[src].distance = 0;
        q.push({src,0});
        BFS(q,dp);
        for(int i = 0 ; i < dp.size(); i++){
            printf("%d %d %d\r\n", i , dp[i].distance, dp[i].parent);
        }
        return dp[dest].distance;
    }
};

//======================================================================//
//INPUT
//    chessKnight_SP knight;
//    printf("shortestPath from 00 tp 77 is %d", knight.shortestPath({0,0}, {7,7}));

typedef pair<int,int> iPair;

struct info{
    iPair loc;
    int dist;
    iPair parent;
};

class chessKnight_SP{
private:
    const int rowMax = 8;
    const int colMax = 8;
    const int rowOffset[8] = {2,2,-2,-2,1,1,-1,-1};
    const int colOffset[8] = {1,-1,1,-1,2,-2,-2,2};
public:
    int shortestPath(iPair src, iPair dest){
        printf("Running ShortestPath");
        
        queue<info>q;
        vector<bool>col(colMax,false);
        vector<vector<bool>> visited(rowMax, col);
        
        visited[src.first][src.second] = true;
        q.push({{src.first,src.second},0,{-1,-1}});
        
        while(!q.empty()){
            info curr = q.front();
            q.pop();
            int x = curr.loc.first;
            int y = curr.loc.second;
            printf("%d %d -- >",x,y);
            if(x == dest.first && y == dest.second){
                return curr.dist;
            }
            for(int i = 0 ; i < 8 ; i++){
                int nextRow = x + rowOffset[i];
                int nextCol = y + colOffset[i];
                printf("%d %d\r\n",nextRow, nextCol);
                if(0 <= nextRow && nextRow < rowMax && 0 <= nextCol && nextCol < colMax && !visited[nextRow][nextCol]){
                    visited[nextRow][nextCol] = true;
                    q.push({{nextRow,nextCol},curr.dist+1,{x,y}});
                }
            }
        }
        return -1;
    }
};

//======================================================================//

class Graph2{
private:
    int V;
    
public:
    list<int>*adj;
    Graph2(){}
    Graph2(int v, vector<Edge>& edges):V(v){
        adj = new list<int>[V];
        for(int i = 0 ; i < edges.size(); i++){
            adj[edges[i].src].push_back(edges[i].dest);
            adj[edges[i].dest].push_back(edges[i].src);
        }
    }
};

struct DisjointNode{
    int parent;
};

class Disjoint{
private:
    vector<DisjointNode>dj;
    int V;
public:
    Disjoint(int v):V(v){dj.resize(V);}
    
    void makeSet(int V){
        for(int i = 0 ; i < V; i++)
        {
            dj[i].parent = i;
        }
    }
    int find(int v){
        if(dj[v].parent == v){
            return v;
        }
        return find(dj[v].parent);
    }
    void unionSet(int x, int y){
        int u = find(x);
        int v = find(y);
        if(u == v){
            return;
        }
        else{
            dj[u].parent = v;
        }
    }
};

bool findCycle(Graph2 &g, int V){
    Disjoint ds(V);
    ds.makeSet(V);
    for(int i = 0 ; i < V; i++){
        for(auto j = g.adj[i].begin(); j != g.adj[i].end(); j++){
            int x = ds.find(i);
            int y = ds.find(*j);
            if(x==y){
                return true;
            }else{
                ds.unionSet(x,y);
            }
        }
    }
    return false;
}

//======================================================================//
//797. All Paths From Source to Target
//INPUT
//    vector<vector<int>>graph = {{4,3,1},{3,2,4},{3},{4},{}};
//    AllPaths a;
//    common_print_2D_vector(a.allPathsSourceTarget(graph));
class AllPaths{
private:
    void util(vector<vector<int>>&graph, int v, vector<vector<int>>&paths, vector<int>&currPath){
        if(v == graph.size()-1){
            paths.push_back(currPath);
        }
        else{
            for(int i = 0 ; i < graph[v].size(); i++){
                currPath.push_back(graph[v][i]);
                util(graph, graph[v][i],paths, currPath);
                currPath.pop_back();
            }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>paths;
        vector<int>currPath;
        currPath.push_back(0);
        util(graph, 0, paths, currPath);
        return paths;
    }
};

//======================================================================//

//1557. Minimum Number of Vertices to Reach All Nodes
class MinNumberOfVertices{
private:
    
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>inEdges(n,0);
        
        for(int i = 0 ; i < n; i++){
            inEdges[edges[i][1]]++;
        }
        
        for(int i = 0 ; i < n; i++){
            if(inEdges[i]==0){
                ans.push_back(inEdges[i]);
            }
        }
        
        return ans;
    }
};

//======================================================================//
//1387. Sort Integers by The Power Value
//INPUT
//    SortIntPowerVal pow;
//    printf("Degree: %d\r\n",pow.getKth(7, 11, 4));

class SortIntPowerVal{
private:
    map<int,vector<int>>adj;
    vector<int>pow;
    int nextNumber(int x){
        return ((x%2)==0)?(x/2):((x*3)+1);
    }
    int findPower(int i){
        int curr = i;
        int degree = 0;
        queue<int>q;
        
        while(adj.find(curr) == adj.end()){
            int next = nextNumber(curr);
            adj[curr].push_back(next);
            curr = next;
        }
        printf("For %d,FOUND at %d\r\n",i,curr);
        q.push(i);
        while(!q.empty()){
            int elem = q.front();
            q.pop();
            printf("pop = %d", elem);
            degree++;
            for(int i = 0; i < adj[elem].size(); i++){
                q.push(adj[elem][i]);
                printf("Push = %d\r\n", adj[elem][i]);
            }
        }
        printf("elem %d,degree %d\r\n",i,degree);
        return degree-1;
    }
public:
    SortIntPowerVal(){}
    int getKth(int lo, int hi, int k) {
        adj[1] = {};
        for(int i = 0; i < (hi-lo)+1; lo++){
            pow.push_back(findPower(lo+i));
        }
        
        sort(pow.begin(), pow.end());
        common_print_1D_vector(pow);
        for(auto i = adj.begin() ; i != adj.end(); i++){
            printf("%d ", i->first);
            for(int j = 0 ; j < i->second.size(); j++){
                printf("%d ", i->second[j]);
            }
            printf("\r\n");
        }
        return pow[k-1];
    }
};



//======================================================================//
//684. Redundant Connection
//INPUT
//    vector<vector<int>>edges = {{1,2},{2,3},{3,1}};
//        vector<vector<int>>edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
//        RedundantConnection rc;
//        common_print_1D_vector(rc.findRedundantConnection(edges));

// Note: this problem can be better solved using Disjoint Unit (find cycle)

class RedundantConnection{
private:
    map<int,vector<int>>adj;
    vector<int>vEdges;
    void createGraph(vector<vector<int>>& edges){
        for(int i = 0; i < (int)edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
    }
    void countEdges(){
        vEdges.resize(adj.size());
        for(auto i = adj.begin(); i != adj.end(); i++){
            vEdges[i->first] = (int)i->second.size();
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        createGraph(edges);
        countEdges();
        for(auto itr = edges.rbegin(); itr != edges.rend() && ans.size() < 2; itr++){
            if(vEdges[(*itr)[0]] > 1 && ans.size() < 2){
                if(ans.size() == 0 || ans[0] != (*itr)[0]){
                    ans.push_back((*itr)[0]);
                }
            }
            if(vEdges[(*itr)[1]] > 1 && ans.size() < 2){
                if(ans.size() == 0 || ans[0] != (*itr)[1]){
                    ans.push_back((*itr)[1]);
                }
            }
        }
        return ans;
    }
};



//======================================================================//

//Note: Below Solution will fail for vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,3},{3,5,1},{5,4,1}};
//Use Dijkstra for shortest paths and return the longest path
//INPUT for longestPath
//    vector<bool> visited(n+1,false);
//    return nwDelay.longestPath(k, visited);

// INPUT for shortestPathDijkstra
//    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,3},{3,5,1},{5,4,1}};
//    printf("NwDealy times %d\r\n",networkDelayTime(times, 5, 2));
struct compare{
    bool operator()(const iPair& a, const iPair& b){
        return a.second < b.second;
    }
};

class nwDelayTime{
private:
    int V;
    list<iPair>*adj;
public:
    nwDelayTime(){}
    nwDelayTime(int v, vector<vector<int>>& times):V(v){
        adj = new list<iPair>[V+1];
        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
    }
    
    int longestPath(int start, vector<bool>&visited){
        visited[start] = true;
        int currentMax = 0;
        for(auto i = adj[start].begin(); i != adj[start].end(); i++){
            if(!visited[i->first]){
                currentMax = max(currentMax, longestPath(i->first, visited) + i->second);
            }
        }
        return currentMax;
    }
    
    int shortestPathDijkstra(int start, vector<DP>&dp){
        int maxDist = 0;
        priority_queue<iPair,vector<iPair>, greater<iPair>> q;
        q.push({start,0});
        while(!q.empty()){
            iPair u = q.top();
            q.pop();
            
            for(auto i = adj[u.first].begin(); i != adj[u.first].end(); i++){
                int newDist = u.second + i->second;
                printf("%d %d, %d %d, newD:%d\r\n", u.first, u.second, i->first, i->second,newDist);
                if(dp[i->first].distance == -1){
                    dp[i->first].distance = newDist;
                    dp[i->first].parent = u.first;
                    q.push({i->first, newDist});
                }
                else if (dp[i->first].distance > newDist ){
                    dp[i->first].distance = newDist;
                    dp[i->first].parent = u.first;
                }
            }
        }
        for(int i = 0; i < dp.size(); i++){
            printf("%d %d\r\n",dp[i].distance, dp[i].parent);
            maxDist = max(maxDist, dp[i].distance);
        }
        return maxDist;
    }
};

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    nwDelayTime nwDelay(n, times);
    vector<DP>dp(n+1, {-1,-1});
    dp[k].distance = 0;
    return nwDelay.shortestPathDijkstra(k, dp);

}

//======================================================================//

// __LOCAL_MAIN__
void run_graph()
{
    
}



//Notes:
//  WeightedGraphs
//    SingleSource Shortest Paths
//        Dijkstra's Shortest Path (Works on Graph with Non-negative weights & Acyclic or Cyclic Graphs & both Directed as well as undirected graphs)
//        Bellman ford's shortest Path (Negative weights & Cyclig Graph)
//        In a DAG, Shortest path using one cycle of Bellman ford
//    All pairs Shortest Path
//        Floyd-Warshall's Algorithm
//            Problem: Transitive Closure of a Graph
//  Disjoint Sets
//      krushkal Minspan tree

    


//How to find cycle in a undirected graph?
//    in Nod{V,parent}, check in DFS/BFS, for all the adj V of current U are not discovered. If discovered check its parents. If parent is not U there is a cross-Edge

//How to find cycle in a directed graph?
//    Keep track of departure times for each node in DFS. Once departure times for all nodes are calculated, check for each node its adj nodes' departure time is <= the node. (u->V) u.departure < v.departure ? there is a cycle : no cycle;

//How to do topological sort?
//  Count in edges of each node. Put all the nodes with zero in edges to queue. Start DFS on Q. deque a vertex when no inEdges left for that vertex, add it to the sorted list. Otherwise, remove that indge.

// How to do Khan's topological sort?
//  Count in edges of each node.

// How to find if the graph is bipartite
//  Change color of the vertex when level changes. If DFS through all the adj vertexes and see if any of adj vertex's color matchs with it self. If Color matchs. graph is not bipartite.
//    This can also be done using level number. If level number of adj vertexes matchs with current, graph is not bipartite.
