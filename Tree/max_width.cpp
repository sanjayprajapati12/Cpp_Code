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

// max width is define as max node at any level
void max_width(Node* root){
    int mx = 0;
    if(root==NULL){
        cout<<mx;
        return;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        mx = max(mx,size);
        for(int i=0 ;i<size ;i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL )q.push(node->left);
            if(node->right != NULL )q.push(node->right);
        }
    }
    cout<<mx<<endl;
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
    

    max_width(root);



    return 0;
}