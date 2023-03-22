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

int p[10004];
void path_bfs(Node* root,int final){
    if(root->data==final){
        cout<<root->data<<endl;
        return;
    }
    for(int i=0 ; i<10005 ; i++) p[i]=i;
    queue<Node*> q;
    q.push(root);

    p[root->data]=-1; 
    while(!q.empty()){
        int size = q.size();
        for(int i=0 ;i<size ;i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL ) {
                q.push(node->left);
                p[node->left->data] = node->data;
            }
            if(node->right != NULL ) {
                q.push(node->right);
                p[node->right->data] = node->data;
            }
        }

    }

    stack<int> s;
    int v = final;
    for(v ; v!=-1  ; v = p[v] ){
        s.push(v);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

bool get_path(Node* root , vector<int> &ans , int x){
    if(!root) return false;

    ans.push_back(root->data);

    if(root->data == x ) return true;

    if(get_path(root->left,ans,x) || get_path(root->right,ans,x)) return true;

    ans.pop_back();
    return false ; 
}

vector<int> recurance(Node* root , int x){
    vector<int> ans ; 
    if(root==NULL) return ans;
    get_path(root,ans,x);
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

    path_bfs(root,9);

    vector<int> ans = recurance(root,9);
    cout<<endl;
    for(auto &x:ans) cout<<x<<" ";
    return 0;
}