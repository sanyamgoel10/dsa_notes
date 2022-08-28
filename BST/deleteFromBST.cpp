#include <iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        
        Node(int d){
            this->val = d;
            this->left = NULL;
            this->right = NULL;
        }
};

vector<int> preorder(Node* root){
    vector<int> ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        if(curr->right){
            st.push(curr->right);
        }
        if(curr->left){
            st.push(curr->left);
        }
    }
    return ans;
}

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        //base case
        root = new Node(data);
        return root;
    }
    if(data > root->val){
        //insert in right part of root
        root->right = insertIntoBST(root->right, data);
    }
    else{
        //insert in left part of root
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node* &root, vector<int>& inputForBST){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

Node* minValue(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int x){
    if(root == NULL){
        return NULL;
    }
    if(root->val == x){
        // 0 child of root
        if(root->left==NULL && root->right==NULL){
            //delete that node and return NULL
            delete root;  
            return NULL;
        }
        
        // 1 child of root
        if(root->left!=NULL && root->right==NULL){
            //left child present
            Node* temp = root->left;    //take the left child and place on root's position
            delete root;    //delete the root
            return temp;
        }
        if(root->right!=NULL && root->left==NULL){
            //right child present
            Node* temp = root->right;   //take the right child and place on root's position
            delete root;    //delete the root
            return temp;
        }
        
        // 2 children of root
        if(root->left && root->right){
            //replacing root with MIN value in right subtree;
            int minInRightSubtree = minValue(root->right)->val;
            root->val = minInRightSubtree;
            root->right = deleteFromBST(root->right, minInRightSubtree);
            return root;
        }
    }
    else if(root->val > x){
        //iterate over left subtree of root
        root->left = deleteFromBST(root->left, x);
        return root;
    }
    else{
        //iterate over right subtree of root
        root->right = deleteFromBST(root->right, x);
        return root;
    }
}

int main()
{
    Node* root = NULL;
    vector<int> inputForBST = {10,5,21,-1};
    createBST(root,inputForBST);
    // 10 8 21 7 27 5 4 3 -1
    
    vector<int> pre;
    pre = preorder(root);
    cout<<"Preorder traversal initially: ";
    for(auto x : pre){
        cout<<x<<" ";
    }
    cout<<endl;
    
    //DELETING A NODE FROM THE BST
    root = deleteFromBST(root, 4);
    
    vector<int> pre1;
    pre1 = preorder(root);
    cout<<"Preorder traversal afterwords: ";
    for(auto x : pre1){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
