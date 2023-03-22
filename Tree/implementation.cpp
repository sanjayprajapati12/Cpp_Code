#include<bits/stdc++.h>
using namespace std;
// All the traversals are here

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
void inorder(Node* root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

// left , right , root 
void postorder(Node* root){
    if(root==NULL)
        return ;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

void levelorder(Node* root){
    if(root==NULL)
        return ;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i=0 ;i<size ;i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL )q.push(node->left);
            if(node->right != NULL )q.push(node->right);
            cout<<node->data<<" ";
        }
    }
}

vector<vector<int>> zig_zag(Node* root){
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;

    queue<Node*> q;
    q.push(root);
    bool left_right = true; 

    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);

        for(int i=0 ;i<size ;i++){
            Node* node = q.front();
            q.pop();

            int idx = (left_right) ? i : (size - 1 - i);

            row[idx] = node->data ; 

            if(node->left != NULL )  q.push(node->left);
            if(node->right != NULL )  q.push(node->right);
            
        }
        left_right = !left_right;
        ans.push_back(row);
    }
    
    return ans;
}

void find_leaf(Node* root){
    if(root->left==NULL && root->right==NULL) {
        cout<<root->data<<" ";
    }
    if(root->left)
        find_leaf(root->left);
    if(root->right)
        find_leaf(root->right);
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
    preorder(root);
    cout<<endl;

    cout<<"Inorder traversal : ";
    inorder(root);
    cout<<endl;

    cout<<"Postorder traversal : ";
    postorder(root);
    cout<<endl;

    cout<<"Levelorder traversal : ";
    levelorder(root);
    cout<<endl;

    cout<<"Zig-Zag traversal : "<<endl;
    vector<vector<int>> ans = zig_zag(root);
    for(auto row : ans){
        for (auto elem: row){
            cout<<elem<<" ";
        }
        cout<<endl;
    }

    cout<<"These are the leaf nodes : ";
    find_leaf(root);

    return 0;
}