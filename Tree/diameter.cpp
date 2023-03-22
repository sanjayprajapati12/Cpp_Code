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

int diameter(Node* root , int ma){
    if(root==NULL) return ma;
    
    int Lh = max_height(root->left);
    int Rh = max_height(root->right);

    ma = max(ma , Lh + Rh);
    diameter(root->left,ma);
    diameter(root->right,ma);
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

    int ma = -1e12;
    cout<<diameter(root,ma)<<endl;
    return 0;
}