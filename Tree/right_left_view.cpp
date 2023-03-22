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

void recursion_r(Node* root,int level , vector<int> &res){
    if(root==NULL) return ;
    if(res.size() == level ) res.push_back(root->data);
    recursion_r(root->right , level + 1 , res);
    recursion_r(root->left , level + 1 , res);
}

vector<int> right(Node* root){
    vector<int> res;
    recursion_r(root,0,res);
    return res;
}

void recursion_l(Node* root,int level , vector<int> &res){
    if(root==NULL) return ;
    
    if(res.size() == level ) res.push_back(root->data);

    recursion_l(root->left , level + 1 , res);
    recursion_l(root->right , level + 1 , res);
}

vector<int> left(Node* root){
    vector<int> res;
    recursion_l(root,0,res);
    return res;
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

    cout<<"Right View : "<<endl;
    vector<int> ans = right(root);
    for(auto &x : ans){
        cout<<x<<" ";
    }
    
    cout<<endl;
    cout<<"Left View : "<<endl;
    vector<int> ans1 = left(root);
    for(auto &x : ans1){
        cout<<x<<" ";
    }

    return 0;
}