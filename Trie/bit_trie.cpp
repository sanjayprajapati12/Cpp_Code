#include<bits/stdc++.h>
using namespace std;

// bit trie 
struct bitTrie{
    const int max_bit = 29 ; 
    int root = 0  ;

    struct Node {
        vector<int> next_node;
        int cnt = 0;
        Node() {
            next_node.resize(2); // 0 or 1
            fill(begin(next_node), end(next_node), -1);
        }
    };

    vector<Node> tree;
    bitTrie(){
        tree.emplace_back();
    }
    

    void add(int val){   
        int node = root;
        tree[node].cnt++;
        for(int i=max_bit;i>=0;i--){
            int bit=1;
            if((val&(1<<i))==0)
                    bit=0;

            if(tree[node].next_node[bit]==-1){
                tree[node].next_node[bit] = tree.size();
                tree.emplace_back();
            }

            node = tree[node].next_node[bit] ; 
            tree[node].cnt++;
        }
    }
 
    int max_xor(int val){
        int ans=0;
        int node = root;
        for(int i=max_bit ; i>=0 ; i--){
            int bit=1;
            if((val&(1<<i))==0)
                    bit=0;
 
            int req=1-bit;

            if(tree[node].next_node[req]==-1){
                node = tree[node].next_node[1-req];
            }
            else if(tree[tree[node].next_node[req]].cnt==0){
                node = tree[node].next_node[1-req];
            }
            else{
                ans += (1LL<<i);
                node = tree[node].next_node[req];
            }
        }
        return ans;
    }

    int min_xor(int val){
        int ans=0;
        int node = root;
        for(int i=max_bit ; i>=0 ; i--){
            int bit=1;
            if((val&(1<<i))==0)
                    bit=0;
 
            int req=bit;

            if(tree[node].next_node[req]==-1){
                ans += (1LL<<i);
                node = tree[node].next_node[1-req];
            }
            else if(tree[tree[node].next_node[req]].cnt==0){
                ans += (1LL<<i);
                node = tree[node].next_node[1-req];
            }
            else{
                node = tree[node].next_node[req];
            }
        }
 
        return ans;
    }
 
    void del(int val){
        int node = root;
        tree[node].cnt--; 
        for(int i=max_bit;i>=0;i--)
        {
            int bit=1;
            if((val&(1<<i))==0)
                    bit=0;

            node = tree[node].next_node[bit];
            tree[node].cnt--;
        }
    }

};


int32_t main(){

    bitTrie bt = bitTrie();
    bt.add(5);
    bt.add(6);

    cout<<bt.max_xor(2)<<endl;
    cout<<bt.min_xor(7)<<endl;
    return 0;
}