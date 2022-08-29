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

vector<int> levelorder(Node* root){
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            Node* curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            ans.push_back(curr->val);
        }
    }
    return ans;
}

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

vector<int> postorder(Node* root){
    vector<int> ans;
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(root);
    while(!st1.empty()){
        Node* curr = st1.top();
        st1.pop();
        if(curr->left){
            st1.push(curr->left);
        }
        if(curr->right){
            st1.push(curr->right);
        }
        st2.push(curr);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}

vector<int> inorder(Node* root){
    vector<int> ans;
    stack<Node*> st;
    while(true){
        if(root==NULL){
            if(st.empty()){
                break;
            }
            root = st.top();
            ans.push_back(root->val);
            st.pop();
            root = root->right;
        }
        else{
            st.push(root);
            root = root->left;
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

int main()
{
    Node* root = NULL;
    vector<int> inputForBST = {10, 8, 21, 7, 27, 5, 4, 3, -1};
    for(auto x : inputForBST){
        root = insertIntoBST(root, x);
    }
    // 10 8 21 7 27 5 4 3 -1
    
    vector<int> pre,in,post,level;
    
    pre = preorder(root);
    in = inorder(root);
    post = postorder(root);
    level = levelorder(root);
    
    cout<<"Preorder traversal: ";
    for(auto x : pre){
        cout<<x<<" ";
    }
    cout<<endl<<"Inorder traversal: ";
    for(auto x : in){
        cout<<x<<" ";
    }
    cout<<endl<<"Postorder traversal: ";
    for(auto x : post){
        cout<<x<<" ";
    }
    cout<<endl<<"Level Order traversal: ";
    for(auto x : level){
        cout<<x<<" ";
    }
    
    return 0;
}
