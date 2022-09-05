#include <bits/stdc++.h>
using namespace std;

// Adjacency List representation of graph

class graph{
public:
    unordered_map<int, vector<int>> adj;
    
    void addEdge(int u, int v, bool direction){
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        
        //creating an edge from u to v
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }
    
    void printAdjList(){
        for(auto x : adj){
            cout<<x.first<<" -> ";
            for(auto y : x.second){
                cout<<y<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n; //number of nodes
    int m; //number of edges
    
    cout<<"Enter number of nodes : ";
    cin>>n;
    cout<<endl<<"Enter number of edges : ";
    cin>>m;
    
    //creating a graph
    graph g;
    
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        
        //creating an edge from u to v
        g.addEdge(u, v, 0);
    }
    
    //printing the graph
    g.printAdjList();

    return 0;
}
