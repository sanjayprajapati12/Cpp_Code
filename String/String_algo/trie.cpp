#include<bits/stdc++.h>
using namespace std;

// int K = 26 ; 

struct Trie{
    struct Vertex{
        int next[26];
        bool leaf;
        int freq;

        Vertex() {
            for(int i=0 ; i<26 ; i++){
                next[i] = -1;
            }
            leaf = false;
            freq = 0 ;
        }
    };

    vector<Vertex> trie;
    Trie(){
        trie.push_back(Vertex());
    }

    void add_string(string const& s) {
        int v = 0;
        trie[v].freq++;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = trie.size();
                trie.emplace_back(Vertex());
            }
            v = trie[v].next[c];
            trie[v].freq++;
        }
        trie[v].leaf = true;
    }

    bool check_prefix(string const& s){
        int v = 0 ;
        for(char ch : s){
            int c = ch-'a';
            if(trie[v].next[c]==-1){
                return false;
            }
            v = trie[v].next[c];
        }
        return true;
    }

    bool check_string(const string &s){

        int v =0 ;
        for(char ch : s){
            int c = ch-'a';
            if(trie[v].next[c]==-1){
                return false;
            }
            v = trie[v].next[c];
        }

        return trie[v].leaf;
    }

};


int32_t main(){
    
    Trie t = Trie();
    t.add_string("sanjay");
    t.add_string("sangle");
    t.add_string("sp");

    return 0;
}