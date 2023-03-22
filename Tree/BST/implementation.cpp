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

Node* search(Node* root ,int x){
    while(root!=NULL && root->data!=x){
        root = (x<root->data) ? root->left : root->right ;
    }
    return root;
}

int ceil(Node* root ,int x){
    int ceil = -1;
    while(root){
        if(root->data==x){
            ceil=root->data;
            return ceil;
        }
        if(x>root->data){
            root= root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

int floor(Node* root ,int x){
    int floor = -1;
    while(root){
        if(root->data==x){
            floor=root->data;
            return floor;
        }
        if(x<root->data){
            root= root->left;
        }
        else{
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}

Node* insert(Node* root ,int x){
    Node* r = root;
    while(1){
        if(x<root->data){
            if(!root->left){
                root->left = new Node(x);
                break;
            }
            root= root->left;
        }
        else{
            if(!root->right){
                root->right = new Node(x);
                break;
            }
            root = root->right;
        }
    }
    return r; 
}

int32_t main(){

    int arr[] = {8,5,12,4,7,6,10,14,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    Node *root = construct(arr,0,n-1);

    Node* r = search(root,0);
    if(!r) cout<<"Not found!"<<endl;
    else    cout<<r->data<<endl;

    root = insert(root,0);

    Node* r1 = search(root,0);
    if(!r1) cout<<"Not found!"<<endl;
    else    cout<<r1->data<<endl;
    
    cout<< ceil(root,9)<<endl;
    cout<< floor(root,9)<<endl;

    return 0;
}

