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

int maximumInBST(Node *root)
{
    int maxi = -1;
    while (root != NULL)
    {
        maxi = root->data;
        root = root->right;
    }
    return maxi;
}

int minimunInBST(Node *root)
{
    int mini = -1;
    while (root != NULL)
    {
        mini = root->data;
        root = root->left;
    }
    return mini;
}

int32_t main(){

    int arr[] = {8,5,12,4,7,6,10,14,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    Node *root = construct(arr,0,n-1);

    cout<<"Maximum : "<<maximumInBST(root)<<endl;
    cout<<"Minimum : "<<minimunInBST(root)<<endl;

    return 0;
}