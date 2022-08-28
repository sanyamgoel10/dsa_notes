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

bool searchInBST(Node* root, int x){
    Node* temp = root;
    
    if(temp == NULL){
        //could not find x in tree
        return false;
    }
    if(temp->val==x){
        return true;
    }
    if(x < temp->val){
        return searchInBST(temp->left, x);
    }
    else{
        return searchInBST(temp->right, x);
    }
}

bool searchIterative(Node* root, int x){
    Node* temp = root;
    while(temp){
        if(x == temp->val){
            return true;
        }
        else if(x < temp->val){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}

Node* minValueInBST(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxValueInBST(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}

int main()
{
    Node* root = NULL;
    vector<int> inputForBST = {10,5,21,-1};
    createBST(root,inputForBST);
    // 10 8 21 7 27 5 4 3 -1
    
    vector<int> pre;
    pre = preorder(root);
    cout<<"Preorder traversal: ";
    for(auto x : pre){
        cout<<x<<" ";
    }
    cout<<endl;
    
    //GETTING THE MIN AND MAXIMUM VALUE IN A BST
    cout<<minValueInBST(root)->val;
    cout<<endl;
    cout<<maxValueInBST(root)->val;
    
    return 0;
}
