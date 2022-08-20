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

int main()
{
    Node* root = NULL;  //creating the root element
    
    root = buildTree(root);     //function to create a tree by taking user values
    
    //Commands : 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    //Created the tree:
    // 1 
    // 2 5
    // 3 4 6 7
    
    return 0;
}
