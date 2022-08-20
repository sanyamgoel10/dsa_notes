#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void allTraversal(Node* root){
    vector<int> preorder;
    vector<int> postorder;
    vector<int> inorder;
    
    stack<pair<Node*, int>> st;   //create a stack to store TreeNode and a number(number to indicate where to go)
    
    st.push({root, 1});   //push root element in the stack to start with
    
    while(!st.empty()){
        pair<Node*,int> temp = st.top();
        
        //Do Preorder
        if(temp.second==1){
            //push in preorder
            preorder.push_back(temp.first->data);
            //num++
            st.top().second++;
            //goleft
            if(temp.first->left){
                st.push({temp.first->left,1});
            }
        }
        //Do Inorder
        else if(temp.second==2){
            //push in inorder
            inorder.push_back(temp.first->data);
            //num++
            st.top().second++;
            //goright
            if(temp.first->right){
                st.push({temp.first->right,1});
            }
        }
        //Do Postorder
        else if(temp.second==3){
            //push in postorder
            postorder.push_back(temp.first->data);
            //pop from stack
            st.pop();
        }
    }
    cout<<"PREORDER TRAVERSAL : ";
    for(auto x : preorder){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"INORDER TRAVERSAL : ";
    for(auto x : inorder){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"POSTORDER TRAVERSAL : ";
    for(auto x : postorder){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    allTraversal(root);
    
    return 0;
}
