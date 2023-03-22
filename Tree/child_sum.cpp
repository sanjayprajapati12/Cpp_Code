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

void child_sum(Node* root){
    if(root==NULL) return ;
    int child = 0;
    if(root->left){
        child += root->left->data;
    }
    if(root->right){
        child += root->right->data;
    }
    if(child >= root->data) root->data = child;
    else{
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    child_sum(root->left);
    child_sum(root->right);

    int tot = 0;
    if(root->left) tot += root->left->data;
    if(root->right) tot += root->right->data;
    if(root->left || root->right) root->data = tot ;


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

    child_sum(root);

    cout<<"Levelorder traversal : ";
    levelorder(root);
    cout<<endl;

    return 0;
}