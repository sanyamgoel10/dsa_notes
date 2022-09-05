#include <bits/stdc++.h>
using namespace std;

// Adjacency Matrix representation of graph

int main()
{
    int n; //number of nodes
    int m; //number of edges
    
    cout<<"Enter number of nodes : ";
    cin>>n;
    cout<<"Enter number of edges : ";
    cin>>m;
    
    //creating a graph with n nodes
    vector<vector<int>> adj(n+1, vector<int>(n+1));
    
    int d;
    cout<<"Enter directed or undirected as 1 or 0 : ";
    cin>>d;
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        
        adj[u][v] = 1;
        if(d==0){
            adj[v][u] = 1;
        }
    }
    
    //printing the graph
    for(int i=0;i<n;i++){
        cout<<i<<" -> ";
        for(int j=0;j<n;j++){
            if(adj[i][j]!=0){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
