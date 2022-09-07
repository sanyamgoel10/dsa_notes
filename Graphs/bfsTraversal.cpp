#include <bits/stdc++.h>
using namespace std;



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
    vector<int> bfs;
    
    vector<int> vis(n);     //visited array to keep track of visited nodes
    
    //this traversal will work well with disconnected graphs as well
    for(int i=0;i<n;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                
                for(auto x : adjList[i]){
                    if(!vis[x]){
                        q.push(x);
                        vis[x] = 1;
                    }
                }
            }
        }
    }
    
    for(auto x : bfs){
        cout<<x<<" ";
    }
    
    return 0;
}
