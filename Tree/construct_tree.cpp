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

// from preorder and inorder
Node* buildTree(vector<int> &preorder , int preStart , int preEnd , vector<int> &inorder , int inStart , int inEnd , map<int,int> inMap){
    if(preStart > preEnd || inStart > inEnd) return NULL;

    Node* root = new Node(preorder[preStart]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart ;

    root->left = buildTree(preorder,preStart + 1 , preStart + numsLeft , inorder , inStart , inRoot - 1 , inMap);
    root->right = buildTree(preorder,preStart + numsLeft + 1 , preEnd , inorder ,  inRoot + 1 , inEnd ,  inMap);
    return root ; 

}


// form postorder and inorder
Node* buildTree1(vector<int> &postorder , int postStart , int postEnd , vector<int> &inorder , int inStart , int inEnd , map<int,int> inMap){
    if(postStart > postEnd || inStart > inEnd) return NULL;

    Node* root1 = new Node(postorder[postEnd]);

    int inRoot = inMap[postorder[postEnd]];
    int numsLeft = inRoot - inStart ;

    root1->left = buildTree1(postorder, postStart  , postStart + numsLeft - 1  , inorder , inStart , inRoot - 1 , inMap);
    root1->right = buildTree1(postorder, postStart + numsLeft , postEnd-1, inorder ,  inRoot + 1 , inEnd ,  inMap);
    return root1 ; 
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
    
    // size of vector of inorder and preorder should be same 
    vector<int> inorder  =  {40,20,50,10,60,30};
    vector<int> preorder  =  {10,20,40,50,30,60};

    map<int,int> inMap; 
    for(int i=0 ; i<inorder.size() ;i++){
        inMap[inorder[i]] = i ;
    }
    // from preorder and inorder
    Node* root = buildTree(preorder , 0 ,preorder.size() - 1 , inorder , 0 , inorder.size() - 1 , inMap);

    cout<<"Levelorder traversal : ";
    levelorder(root);
    cout<<endl;

    // from postorder and inorder
    // vector<int> inorder  =  {40,20,50,10,60,30}; alreay define above
    vector<int> postorder  =  {40,50,20,60,30,10};
    Node* root1 = buildTree1(postorder , 0 , postorder.size() - 1 , inorder , 0 , inorder.size() - 1 , inMap);

    cout<<"Levelorder traversal : ";
    levelorder(root1);
    cout<<endl;

    return 0;
}