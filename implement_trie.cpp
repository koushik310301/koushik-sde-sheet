/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
#include<bits/stdc++.h>

class Node{
  
    public:
    Node* links[26];
    bool end;
    
    Node(){
        end=false;
    }
    
    Node(char c){
        links[c-'a'] = new Node();
        end=false;
    }
   
};

class Trie {

public:

    /** Initialize your data structure here. */
    Node* root;
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* tmp=root;
        for(char c : word){
            if(tmp->links[c-'a']==NULL){
                tmp->links[c-'a']=new Node();
            }
            tmp=tmp->links[c-'a'];
        }
        tmp->end=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* tmp=root;
        for(char c : word){
            if(tmp->links[c-'a']==NULL) return false;
            tmp=tmp->links[c-'a'];    
        }
        return tmp->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* tmp=root;
        for(char c : prefix){
            if(tmp->links[c-'a']==NULL) return false;
            tmp=tmp->links[c-'a'];
        }
        return true;
    }
};