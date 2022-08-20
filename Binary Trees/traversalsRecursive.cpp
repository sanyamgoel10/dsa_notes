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

void printPreorder(Node* root){
    if(root==NULL){
        return;
    }
    // NLR -> Node Left Right
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node* root){
    if(root==NULL){
        return;
    }
    // LNR -> Left Node Right
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPostorder(Node* root){
    if(root==NULL){
        return;
    }
    // LRN -> Left Right Node
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
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
    
    cout<<endl;
    
    //Printing Preorder Traversal by recursion
    cout<<"Preorder : ";
    printPreorder(root);
    cout<<endl;
    //Printing Inorder Traversal by recursion 
    cout<<"Inorder : ";
    printInorder(root);
    cout<<endl;
    //Printing Postorder Traversal by recursion
    cout<<"Postorder : ";
    printPostorder(root);
    cout<<endl;
    
    return 0;
}
