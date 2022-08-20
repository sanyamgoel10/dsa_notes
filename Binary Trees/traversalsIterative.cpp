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

vector<int> printPreorder(Node* root){
    vector<int> ans;
    
    stack<Node*> st;    //use a single stack
    st.push(root);      //insert root value int the stack
    
    //run a loop till stack is not empty
    while(!st.empty()){
        Node* temp = st.top();
        //pop the topmost element from stack and push in answer
        st.pop();
        ans.push_back(temp->data);
        
        //push left of the popped node in stack
        if(temp->right)
            st.push(temp->right);
        //push right of the popped node in stack
        if(temp->left)
            st.push(temp->left);
    }
    
    return ans;
}

vector<int> printInorder(Node* root){
    vector<int> ans;
    
    stack<Node*> st;    //use a single stack
    
    //run an infinite loop till the stack is empty
    while(true){
        //if current node is NULL push the st.top() in answer and goto right of node
        if(root == NULL){
            //break the infinite loop whenever the stack empty is reached
            if(st.empty()){
                break;
            }
            root = st.top();
            ans.push_back(root->data);
            st.pop();
            root = root->right;
        }
        //if the current node is not NULL goto the leftmost node while pushing in stack
        else{
            st.push(root);
            root = root->left;
        }
    }
    
    return ans;
}

vector<int> printPostorder(Node* root){
    vector<int> ans;
    
    //use two stacks 
    stack<Node*> st1;  
    stack<Node*> st2;
    
    st1.push(root);     //push root element in the stack1
    
    //push the current element in stack2 while popping the current element from stack1
    while(!st1.empty()){
        Node* temp = st1.top();
        st1.pop();
        //push currentnode->left in stack1
        if(temp->left)
            st1.push(temp->left);
        //push currentnode->right in stack1
        if(temp->right)
            st1.push(temp->right);
        st2.push(temp);
    }
    
    //stack2 contains the results of Preorder
    //store those results in answer
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    
    return ans;
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
    cout<<endl;
    
    //Printing Preorder Traversal Iterative
    cout<<"Preorder : ";
    vector<int> pre = printPreorder(root);
    for(auto x : pre){
        cout<<x<<" ";
    }
    cout<<endl;
    //Printing Inorder Traversal Iterative
    cout<<"Inorder : ";
    vector<int> ino = printInorder(root);
    for(auto x : ino){
        cout<<x<<" ";
    }
    cout<<endl;
    //Printing Postorder Traversal Iterative
    cout<<"Postorder : ";
    vector<int> post = printPostorder(root);
    for(auto x : post){
        cout<<x<<" ";
    }
    cout<<endl;
    
    return 0;
}
