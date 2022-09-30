#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> createGraph(int& n, int& m, int& d, vector<pair<int,int>>& edges){
    unordered_map<int,vector<int>> adjList;
    for(auto x : edges){
        int u = x.first;    // 1st node
        int v = x.second;   // 2nd node
        
        if(d==0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else{
            adjList[u].push_back(v);
        }
    }
    return adjList;
}

void dfsTravUtil(int i, unordered_map<int,vector<int>>& adjList, vector<int>& vis, vector<int>& dfs){
    dfs.push_back(i);
    vis[i] = 1;
    for(auto neighbor : adjList[i]){
        if(!vis[neighbor]){
            dfsTravUtil(neighbor, adjList, vis, dfs);
        }
    }
}

vector<int> dfsTrav(int& n, unordered_map<int,vector<int>>& adjList){
    vector<int> dfs;
    //creating a visited array to keep track of visited nodes
    vector<int> vis(n); 
    
    for(int i=0;i<n;i++){
        if(!vis[i])
            dfsTravUtil(0, adjList, vis, dfs);
    }
    
    return dfs;
}

int main() {
    // ADJACENCY LIST GRAPH CREATION
    int n = 5;  //number of vertices
    int m = 7;  //number of edges
    //vector containing edges between nodes
    //edges.size() = m
    vector<pair<int,int>> edges = {{0,1},{0,4},{0,2},{4,2},{1,2},{1,3},{2,3}};    
    //directed or undirected graph
    int d = 0;  // 0->undirected, 1-directed
    //adjacency list
    unordered_map<int,vector<int>> adjList = createGraph(n, m, d, edges);
    
    
    // PRINTING THE GRAPH
    cout<<"Printing the Graph :-"<<endl;
    for(auto node : adjList){
        int i = node.first;
        vector<int> j = node.second;
        cout<<i<<" -> ";
        for(auto neighbor : j){
            cout<<neighbor<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    
    //DFS TRAVERSAL OF THE GRAPH
    cout<<"DFS traversal of the graph :-"<<endl;
    vector<int> dfs = dfsTrav(n, adjList);
    for(auto x : dfs)
        cout<<x<<", ";
    cout<<endl;
}
