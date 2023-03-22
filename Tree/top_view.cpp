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

vector<int> top_view(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    // vertical , node->value
    map<int,int> map;

    // node , vertical(line)
    queue<pair<Node* , int>> q;
    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first ; 
        int line = it.second;
        if(map.find(line) == map.end()) map[line] = node->data ; 
        
        if(node->left !=NULL){
            q.push({node->left , line - 1});
        }

        if(node->right !=NULL){
            q.push({node->right , line + 1});
        }
    }

    for(auto it:map){
        ans.push_back(it.second);
    }

    return ans ; 
}

vector<int> bottom_view(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;

    // vertical , node->value
    map<int,int> map;

    // node , vertical(line)
    queue<pair<Node* , int>> q;
    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first ; 
        int line = it.second;
        map[line] = node->data ; 
        
        if(node->left !=NULL){
            q.push({node->left , line - 1});
        }

        if(node->right !=NULL){
            q.push({node->right , line + 1});
        }
    }

    for(auto it:map){
        ans.push_back(it.second);
    }

    return ans ; 
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

    cout<<"Top View : "<<endl;
    vector<int> ans = top_view(root);
    for(auto &x : ans){
        cout<<x<<" ";
    }

    cout<<endl;
    cout<<"Bottom View : "<<endl;
    vector<int> ans1 = bottom_view(root);
    for(auto &x : ans1){
        cout<<x<<" ";
    }

    return 0;
}