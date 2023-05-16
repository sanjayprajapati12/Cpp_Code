#include<bits/stdc++.h>
using namespace std;

// trie , root = 0 

const int letters = 26;
struct Node {
    vector<int> next_node;
    int is_leaf = 0;  // count full string 
    int cnt = 0;  // count prefix 
    Node() {
        next_node.resize(letters);
        fill(begin(next_node), end(next_node), -1);
    }
};

struct Trie{
    vector<Node> tree;
    Trie(){
        tree.emplace_back();
    }

    void add_string(string s) {
        int node = 0;
        for(char c : s){
            int index = c - 'a';
            if(tree[node].next_node[index] == -1) {
                  tree[node].next_node[index] = tree.size();
                  tree.emplace_back();
            }
            tree[node].cnt++;
            node = tree[node].next_node[index];
        }
        tree[node].cnt++;
        tree[node].is_leaf++;
        return ;
    }

    int string_count(string s){
        int node = 0 ;
        for(auto &c:s){
            int index = c-'a';
            if(tree[node].next_node[index]==-1){
                return 0;
            }
            node = tree[node].next_node[index];
        }
        return (tree[node].is_leaf);
    }

    int prefix_count(string s){
        int node = 0 ;
        for(auto &c:s){
            int index = c-'a';
            if(tree[node].next_node[index]==-1){
                return 0;
            }
            node = tree[node].next_node[index];
        }
        return (tree[node].cnt);
    }

};

int32_t main(){

    Trie t = Trie();
    t.add_string("sanjay");
    t.add_string("sanjay");
    t.add_string("sanju");
    cout<<t.prefix_count("sanjay")<<endl;
    cout<<t.prefix_count("san")<<endl;
    cout<<t.string_count("sanjay")<<endl;

    return 0;
}