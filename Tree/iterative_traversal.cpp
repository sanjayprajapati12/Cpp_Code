#include<bits/stdc++.h>
using namespace std;
// All the traversals are here
// Error code

#define int long long int
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        left=right=NULL;
    }
};

// root , left , right
void preorder(Node* root){
    if(root==NULL)
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// left , root , right
vector<int> inorder(Node* root){
    stack<Node*> st;
    Node* node = root; 
    vector<int> inorder;
    while(true){
        if(node!=NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()==true)break;
            node= st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}

// left , right , root 
vector<int> postorder(Node* root){
    stack<Node*> st;
    Node* cur = root; 
    vector<int> postorder;
    while(cur!=NULL || !st.empty()){
        if(cur!=NULL){
            st.push(cur);
            cur = cur->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp==NULL){
                temp = st.top();
                st.top();
                postorder.push_back(temp->data);
                while(!st.empty() &&temp==st.top()->right){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else{
                cur = temp;
            }
        }    
    }
    return postorder;
}

int32_t main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);

    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    cout<<"Preorder traversal : ";
    // 1 2 4 5 6 3 7 8 9 10
    preorder(root);
    cout<<endl;

    cout<<"Inorder traversal : ";
    // 4 2 6 5 1 7 3 9 8 10
    vector<int> v = inorder(root);
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<"Postorder traversal : ";
    // 4 6 5 2 7 9 10 8 3 1 
    vector<int> v1 = postorder(root);
    for(auto &x:v1){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}