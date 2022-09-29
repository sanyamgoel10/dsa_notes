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
    
    //push starting node in the queue and mark it visited
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    
    while(!q.empty()){
        //push front node in bfs and pop from queue
        int currNode = q.front();
        q.pop();
        bfs.push_back(currNode);
        for(auto neighbor : adjList[currNode]){
            //push neighboring nodes in the queue
            if(!vis[neighbor]){
                q.push(neighbor);
                vis[neighbor] = 1;
            }
        }
    }
    return bfs;
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
    
    
    //BFS TRAVERSAL OF THE GRAPH
    cout<<"BFS traversal of the graph :-"<<endl;
    vector<int> bfs = bfsTrav(n, adjList);
    for(auto x : bfs)
        cout<<x<<", ";
    cout<<endl;
}
