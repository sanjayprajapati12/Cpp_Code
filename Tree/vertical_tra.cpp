#include<bits/stdc++.h>
using namespace std;
// heavy data structure use(just kidding😂)

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

vector<vector<int>> vertical(Node* root){

    // stores vertical(line) , level , node->data 
    map<int,map<int,multiset<int>>> nodes;

    // stores node , vertical(line) , level
    queue<pair<Node* , pair<int,int>>> todo ; 
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        Node* node = p.first ;
        int line = p.second.first ; 
        int level = p.second.second ; 
        nodes[line][level].insert(node->data);
        if(node->left){
            todo.push({node->left ,{line-1,level+1}});
        }
        if(node->right){
            todo.push({node->right ,{line+1,level+1}});
        }

    }
       
        vector<vector<int>> ans; 
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                // col.insert(col.end(),q.second.begin(),q.second.end());
                // if u don't want to run for - loop then u can use above singel line
                for(auto x : q.second){
                    col.push_back(x);
                }
            }
            ans.push_back(col);
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

    cout<<"Vertical traversal : "<<endl;
    vector<vector<int>> ans = vertical(root);
    for(auto row : ans){
        for (auto elem: row){
            cout<<elem<<" ";
        }
        cout<<endl;
    }

    return 0;
}