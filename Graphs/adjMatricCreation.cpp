#include<bits/stdc++.h>
using namespace std;

int main() {
    // ADJACENCY MATRIX GRAPH CREATION
    int n = 5;  //number of vertices
    int m = 7;  //number of edges
    
    //vector containing edges between nodes
    //edges.size() = m
    vector<pair<int,int>> edges = {{1,2},{1,5},{1,3},{5,3},{2,3},{2,4},{3,4}};
    
    //adjacency matrix
    vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, 0));
    
    //directed or undirected graph
    int d = 0;  // 0->undirected, 1-directed
    
    for(auto x : edges){
        int u = x.first;    // 1st node
        int v = x.second;   // 2nd node
        
        if(d==0){
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
        else{
            adjMatrix[u][v] = 1;
        }
    }
    
    // PRINTING THE GRAPH
    for(int i=0;i<n;i++){
        cout<<i<<" -> ";
        for(int j=0;j<n;j++){
            if(adjMatrix[i][j] == 1){
                cout<<j<<", ";
            }
        }
        cout<<endl;
    }
}
