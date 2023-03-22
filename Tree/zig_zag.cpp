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

vector<vector<int>> zig_zag(Node* root){
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;

    queue<Node*> q;
    q.push(root);
    bool left_right = true; 

    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);

        for(int i=0 ;i<size ;i++){
            Node* node = q.front();
            q.pop();

            int idx = (left_right) ? i : (size - 1 - i);

            row[idx] = node->data ; 

            if(node->left != NULL )  q.push(node->left);
            if(node->right != NULL )  q.push(node->right);
            
        }
        left_right = !left_right;
        ans.push_back(row);
    }
    
    return ans;
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

    cout<<"Zig-Zag traversal : "<<endl;
    vector<vector<int>> ans = zig_zag(root);
    for(auto row : ans){
        for (auto elem: row){
            cout<<elem<<" ";
        }
        cout<<endl;
    }

    return 0;
}