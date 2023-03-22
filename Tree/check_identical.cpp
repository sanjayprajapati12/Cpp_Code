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

bool isSame(Node* root1 , Node* root2){
    if(root1==NULL || root2==NULL){
        return (root1==root2);
    }
    return (root1->data == root2->data) && isSame(root1->left,root2->left) && isSame(root1->right,root2->right);
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

    if(isSame(root,root)){
        cout<<"Same tree";
    }
    else cout<<"Not same tree";

    return 0;
}