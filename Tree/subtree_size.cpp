#include<bits/stdc++.h>
using namespace std;


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
int subtree_size(Node* root,vector<int> &subtree){
    if(root==NULL)
        return 0;
    
    subtree[root->data] = 1 + subtree_size(root->left,subtree) + subtree_size(root->right,subtree);
    return subtree[root->data] ;
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

    // here n = 10
    int n=10;
    vector<int> subtree(n+1);

    cout<<subtree_size(root,subtree)<<endl;

    for(int i=1 ;i<n+1 ;i++) cout<<i<<" "<<subtree[i]<<endl;

    return 0;
}