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



bool is_symmetric(Node* L , Node* R){
    if(R==NULL || L==NULL) return (L==R);
    if(L->data != R->data ) return false ;

    return is_symmetric(L->left,R->right) && is_symmetric(L->right,R->left) ;
}

int32_t main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(5);
    // root->left->right = new Node(5);
    
    root->right->right = new Node(5);
    


    if(is_symmetric(root->left , root->right))
        cout<<"Tree is symmetric"<<endl;
    else cout<<"Tree is not symmetric"<<endl;
        
    return 0;
}