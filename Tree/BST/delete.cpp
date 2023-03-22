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

Node *construct(int arr[], int lo, int hi)
{
    if (lo > hi)
        return NULL;

    int mid = (lo + hi) / 2;
    Node *node = new Node(arr[mid]);
    node->left = construct(arr, lo, mid - 1);
    node->right = construct(arr, mid + 1, hi);

    return node;
}

// this is for helping helper ! nice one 😂
Node *rightMost(Node *root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

// this helper is for delete function
Node *helper(Node *root){
    // case for having only one children
    if (root->left == NULL){
        return root->right;
    }
    if (root->right == NULL){
        return root->left;
    }

    
    Node *rightChild = root->right;
    Node *lastRight = rightMost(root->left);

    lastRight->right = rightChild;

    return root->left;
}

Node* del(Node* root ,int x){
    if(!root) return NULL;

    if(root->data==x) return helper(root);

    Node* r = root;
    while(1){
        if(x<root->data){
            if(root->left!=NULL && root->left->data==x){
                root->left = helper(root->left);
                break;
            }
            root= root->left;
        }
        else{
            if(root->right!=NULL && root->right->data==x){
                root->right = helper(root->right);
                break;
            }
            root = root->right;
        }
    }

    return r; 
}


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



int32_t main(){

    int arr[] = {8,5,12,4,7,6,10,14,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    Node *root = construct(arr,0,n-1);

    cout<<"Levelorder traversal : ";
    levelorder(root);
    cout<<endl;
    
    root = del(root,5);

    cout<<"Levelorder traversal : ";
    levelorder(root);
    cout<<endl;


    return 0;
}