#include <bits/stdc++.h>
using namespace std;

void dfsTrav(int i, vector<int> adjList[], vector<int>& vis, vector<int>& dfs){
    //push current node in dfs
    dfs.push_back(i);
    //mark that node as visited
    vis[i] = 1;
    //goto current nodes's neighbors and find its dfs
    for(auto x : adjList[i]){
        if(!vis[x]){
            dfsTrav(x, adjList, vis, dfs);
        }
    }
}

int main()
{
    //First, I'll represent graph using an adjacency list
    
    int n = 5;  //number of nodes
    int e = 4;  //number of edges
    
    //size of adjacency list is (n + 1), to store each nodes starting from 0
    //vector in adjList stores nodes connecting each node
    vector<int> adjList[n+1];  //adjascency list
    
    //vector containing all pairs of edges in input graph
    vector<pair<int,int>> edges = {{0,1},{0,2},{0,3},{2,4}};
    
    for(int i=0;i<e;i++){
        int u, v;
        u = edges[i].first;
        v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    // bfs traversal of the graph
    vector<int> dfs;
    vector<int> vis(n+1);
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            //if node is not visited earlier, then only go to its dfs traversal
            dfsTrav(i, adjList, vis, dfs);
        }
    }
    
    for(auto x : dfs){
        cout<<x<<" ";
    }
    
    return 0;
}
