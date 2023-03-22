#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *next[26];
    bool end = false;
    // int cntEnd = 0 ;
    // int cntPrefix = 0 ;

    bool containsKey(char ch){
        return (next[ch-'a'] !=NULL);
    }

    void put(char ch , Node* node){
        next[ch - 'a'] = node ; 
    }

    Node* get(char ch){
        return next[ch-'a'];
    }

    bool setEnd(){
        end = true;
    }

    bool isEnd(){
        return end;
    }

    // void increaseEnd(){
    //     cntEnd++;
    // }

    // void deleteEnd(){
    //     cntEnd--;
    // }

    // void increasePrefix(){
    //     cntPrefix++;
    // }

    // void deletePrefix(){
    //     cntPrefix--;
    // }
};

class Trie{
    private: Node* root;

    public:
        Trie(){
            root = new Node();
        }

        //tc -> O(string_length())
        void insert(string word){
            Node* node = root;
            for(int i=0 ; i<word.length();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i] , new Node());
                }

                // moves to new reference trie
                node = node->get(word[i]);
            }
            node->setEnd();
        }

        //tc -> O(string_length())
        bool search(string word){
            Node* node = root ;
            for(int i=0 ; i < word.length() ; i++){
                if(!node->containsKey(word[i])){
                    return false;
                }

                // moves to new reference trie
                node = node->get(word[i]);
            }

            return node->isEnd();
        }

        //tc -> O(string_length())
        bool startsWith(string word){
            Node* node = root ;
            for(int i=0 ;i<word.length() ; i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                
                // moves to new reference trie
                node = node->get(word[i]);
            }
            return true;
        }
};

int main(){

    Trie t;
    t.insert("sanjay");

    return 0;
}