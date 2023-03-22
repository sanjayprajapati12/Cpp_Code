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

int max_height(Node* root){
    if(root==NULL) return 0;

    return (1 + max(max_height(root->left),max_height(root->right)) );
}

bool is_balanced(Node* root){
    if(root==NULL) return true;

    int Lh = max_height(root->left);
    int Rh = max_height(root->right);
    if(abs(Lh-Rh)>1) return false ;
    
    bool left = is_balanced(root->left);
    bool right = is_balanced(root->right);
    if(!left || !right) return false ; 

    return true;
}

int32_t main(){

    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);

    root->left->left = new Node(5);
    // root->left->right = new Node(4);
    root->left->left->left = new Node(7);
    // root->left->left->right  = new Node(6);


    // root->right->left = new Node(7);
    // root->right->right = new Node(8);
    // root->right->right->left = new Node(9);
    // root->right->right->right = new Node(10);


    if(is_balanced(root))
        cout<<"Tree is balanced"<<endl;
    else cout<<"Tree is not balanced"<<endl;
        
    return 0;
}