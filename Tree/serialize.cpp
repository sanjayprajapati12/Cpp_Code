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

string serialize(Node* root){
    if(!root) return "";
    string s = "";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node==NULL) s+="#,";
        else{
            s.append(to_string(node->data)+',');
        }

        if(node!=NULL){
            q.push(node->left);
            q.push(node->right);
        }
    }

    return s;
}

// Node* deserialize(string s){
//     if(s.size()==0) return NULL;
//     stringstram s()
// }

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

   string s = serialize(root);
   cout<<s<<endl;
//    Node* root = deserialize(s);

    return 0;
}