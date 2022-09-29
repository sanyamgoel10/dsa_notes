#include<bits/stdc++.h>
using namespace std;

int main() {
    // ADJACENCY LIST GRAPH CREATION
    int n = 5;  //number of vertices
    int m = 7;  //number of edges
    
    //vector containing edges between nodes
    //edges.size() = m
    vector<pair<int,int>> edges = {{1,2},{1,5},{1,3},{5,3},{2,3},{2,4},{3,4}};
    
    //adjacency list
    unordered_map<int,vector<int>> adjList;
    
    // //another method to create an adjacency list
    // vector<int> adjList[n+1];
    
    //directed or undirected graph
    int d = 0;  // 0->undirected, 1-directed
    
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
    
    // PRINTING THE GRAPH
    for(auto node : adjList){
        int i = node.first;
        vector<int> j = node.second;
        cout<<i<<" -> ";
        for(auto neighbor : j){
            cout<<neighbor<<", ";
        }
        cout<<endl;
    }
}
