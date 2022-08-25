//   PROGRAM TO FIND FIND A PATH FRO ROOT NODE TO A GIVEN NODE IN TREE

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
    cin>>data;
    
    root = new Node(data);
    
    if(data==-1){
        return NULL;
    }
    
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    
    return root;
}

bool solve(Node* root, vector<int>& ans, int B){
    //reached the leaf node and B not found
    if(root==NULL){
        return false;
    }
    
    //adding the current node to the path
    ans.push_back(root->val);
    
    //if node B found at current node
    if(root->val==B){
        return true;
    }
    
    //if node B not found, check for its presence in left and right subtree
    //return true if B found in any of the left or right subtree
    if(solve(root->left, ans, B) || solve(root->right, ans, B)){
        return true;
    }
    
    //removing current node from the path if B not present in its subtree (Backtrack step)
    ans.pop_back();
    
    //B not found at current node
    return false;
}
vector<int> getPath(Node* root, int B){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    
    solve(root, ans, B);
    
    return ans;
}

int main() {
    Node* root = NULL;
    root = buildTree(root);
    // 1 2 3 4 5 -1 -1 -1 -1 6 7 -1 -1 -1 -1
    
    //PROGRAM TO FIND PATH BETWEEN ROOT AND A GIVEN NODE IN TREE
    vector<int> path;
    int pathTo = 7; //given node
    path = getPath(root, pathTo);
    
    for(auto x : path){
        cout<<x<<" ";
    }
    
    return 0;
}
