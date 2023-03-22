#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        left=right=NULL;
    }
};

int maxPath_down(Node* root,int &ma){
    if(root==NULL) return 0;
    
    int Lsum = max(0 , maxPath_down(root->left , ma));
    int Rsum = max(0 , maxPath_down(root->right , ma));
    
    ma = max (ma , Lsum + Rsum + root->data );
    return root->data + max( Lsum , Rsum );
}

int maxPath_sum(Node* root){
    int ma = INT_MIN;
    maxPath_down(root,ma);
    return ma;
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

    cout<<maxPath_sum(root)<<endl;
    return 0;
}  