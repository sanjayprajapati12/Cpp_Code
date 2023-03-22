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

int findL(Node* root){
    int height = 0;
    while(root){
        height++;
        root = root->left ;
    }
    return height;
}

int findR(Node* root){
    int height = 0;
    while(root){
        height++;
        root = root->right ;
    }
    return height;
}

int countNodes(Node* root){
    if(root==NULL) return 0;
    
    int l = findL(root);
    int r = findR(root);

    if(l==r) return ( 1<<l ) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
    
}

int32_t main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);


    root->right->left = new Node(7);
    root->right->left->right = new Node(6);
    root->right->left->left = new Node(11);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    cout<<countNodes(root)<<endl;
    return 0;
}