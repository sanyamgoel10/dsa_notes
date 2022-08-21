#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        //parametrized constructor for tree creation
        Node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* buildTree(Node* root){
    //take user input
    cout<<"Enter value : ";
    int data;
    cin>>data;
    
    //create a node with data
    root = new Node(data);
    
    //when user doesn't want to enter more data
    if(data==-1){
        return NULL;
    }
    
    //take user input for left of root
    cout<<"Enter data for inserting in left of "<<data<<" : ";
    root->left = buildTree(root->left);
    
    //take user input for right of root
    cout<<"Enter data for inserting in right of "<<data<<" : ";
    root->right = buildTree(root->right);
    
    return root;
}

void levelOrder(Node* root, vector<vector<int>>& ans){
    if(root==NULL){
        return;
    }
    
    //we use a queue data structure for this
    queue<Node*> q;
    //push root element in root
    q.push(root);  
    
    while(!q.empty()){
        int n = q.size();   //size of the queue
        vector<int> temp;   //temporary array to store current level values
        
        //pop all the values of current level from queue and store them in temp
        for(int i=0;i<n;i++){
            Node* curr = q.front();
            q.pop();
            //push left element of curr if present
            if(curr->left){
                q.push(curr->left);
            }
            //push right element of curr if present
            if(curr->right){
                q.push(curr->right);
            }
            temp.push_back(curr->data);
        }
        ans.push_back(temp);    //finally pushing temp to answer
    }
}

int main()
{
    Node* root = NULL;  //creating the root element
    
    root = buildTree(root);     //function to create a tree by taking user values in level order
    
    //Commands : 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    //Created the tree:
    // 1 
    // 2 5
    // 3 4 6 7
    
    cout<<endl;
    
    //Printing Level Order Traversal
    vector<vector<int>> lev;
    levelOrder(root, lev);
    for(auto x : lev){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
