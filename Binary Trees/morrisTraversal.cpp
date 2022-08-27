#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        
        Node(int data){
            this->val = data;
            this->left = NULL;
            this->right = NULL;
        }
};
Node* buildTree(Node* root){
    int data;
    cout<<"Enter value: ";
    cin>>data;
    
    root = new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter left value of "<<data<<": ";
    root->left = buildTree(root->left);
    cout<<"Enter right value of "<<data<<": ";
    root->right = buildTree(root->right);
    
    return root;
}

void morrisTraversal(Node* root, vector<int>& inorder){
    Node* curr = root;
    while(curr){
        //if left of a node not present, print it, and goto its right
        if(curr->left==NULL){
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        //if left of a node present, goto rightmost node of its left subtree
        else{
            Node* prev = curr->left;    //rightmost node of left subtree of curr
            while(prev->right!=NULL && prev->right!=curr){
                prev = prev->right;
            }
            //if thread not present, create a new thread
            if(prev->right==NULL){
                prev->right = curr;
                curr = curr->left;
            }
            //if thread already present, print the value, and remove the thread, and goto right of curr
            else{
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    
    //Program for inorder using MORRIS TRAVERSAL
    vector<int> inorder;
    morrisTraversal(root, inorder);
    
    //Printing the values of inorder
    for(auto x: inorder){
        cout<<x<<" ";
    }
    
    return 0;
}
