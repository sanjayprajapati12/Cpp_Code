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

void printInRange(Node *root, int l, int r){
    if (root == NULL)
        return;

    if(l < root->data && r < root->data){
        printInRange(root->left, l, r);
    }
    else if (l > root->data && r > root->data){
        printInRange(root->right, l, r);
    }
    else{
        printInRange(root->left, l, r);
        cout << root->data << " ";
        printInRange(root->right, l, r);
    }
}

int32_t main(){

    int arr[] = {8,5,12,4,7,6,10,14,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    Node *root = construct(arr,0,n-1);

    printInRange(root,5,10);
    return 0;
}