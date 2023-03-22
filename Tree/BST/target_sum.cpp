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


bool find(Node *root, int key){
    if (root == NULL){
        return false;
    }

    if (key > root->data){
        return find(root->right, key);
    }
    else if (key < root->data){
        return find(root->left, key);
    }
    else{
        return true;
    }              
}

void targetSumSubset(Node *root, Node *node, int target)
{
    if (node == NULL)
        return;

    targetSumSubset(root, node->left, target);

    if (node->data < target){
        int rem = target - node->data;
        if (rem > node->data){
            if (find(root, rem)){
                cout << node->data << " " << rem << endl;
            }
        }
    }

    targetSumSubset(root, node->right, target);
}

void inorder(Node *root, vector<int> &in){
    if (root == NULL)  return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

int32_t main(){

    int arr[] = {8,5,12,4,7,6,10,14,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    Node *root = construct(arr,0,n-1);

    int target=12;
    // O(n*log(n))-time
    // O(log(n)) - call stack
    targetSumSubset(root,root,target);

    // method 2
    // O(n)-time
    // O(n)-space
    cout<<"Method 2: \n";
    vector<int> in;
    inorder(root, in);

    //inorder se sorted array milega

    int left = 0;
    int right = in.size() - 1;

    while (left < right){
        if (in[left] + in[right] > target){
            right--;
        }
        else if (in[left] + in[right] < target){
            left++;
        }
        else{
            cout << in[left] << " " << in[right] << endl;
            left++;
            right--;
        }
    }

    return 0;
}