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

vector<int> bfsTrav(int& n, unordered_map<int,vector<int>>& adjList){
    vector<int> bfs;
    //creating a visited array to keep track of visited nodes
    vector<int> vis(n); 
    
    //we add extra loop to counter disconnected components
    for(int i=0;i<n;i++){
        if(!vis[i]){
            //same as original bfs from here
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int currNode = q.front();
                q.pop();
                bfs.push_back(currNode);
                for(auto neighbor : adjList[currNode]){
                    if(!vis[neighbor]){
                        q.push(neighbor);
                        vis[neighbor] = 1;
                    }
                }
            }
        }
    }
    
    return bfs;
}

int main() {
    // ADJACENCY LIST GRAPH CREATION
    int n = 7;  //number of vertices
    int m = 6;  //number of edges
    //vector containing edges between nodes
    //edges.size() = m
    vector<pair<int,int>> edges = {{0,1},{1,2},{1,6},{4,6},{4,2},{3,5}};    
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
    
    
    //BFS TRAVERSAL OF THE GRAPH
    cout<<"BFS traversal of the graph :-"<<endl;
    vector<int> bfs = bfsTrav(n, adjList);
    for(auto x : bfs)
        cout<<x<<", ";
    cout<<endl;
}
