#include<bits/stdc++.h>
// class Node{
//      public:
//      Node* links[26];
//      int endWith;
//      int prefixCount;
//      Node(){
//          endWith=0;
//          prefixCount=0;
//      }
//      Node(char c ){
//          links[c-'a']=new Node();
//          endWith=0;
//          prefixCount=0;
//      }
//      void increasePrefix(){
//          prefixCount++;
//      }
    
//      void increaseEnd(){
//          endWith++;
//      }
    
//     void reducePrefix(){
//          prefixCount--;
//      }
    
//      void reduceEnd(){
//          endWith--;
//      }
    
//      int getEnd(){
//          return endWith;
//      }
    
//      int getPrefix(){
//          return prefixCount;
//      }
    
//      bool containsKey(char c){
//          return links[c-'a']==NULL;
//      }
    
//      Node* get(char c){
//          return links[c-'a'];
//      }
    
    
    
    
    
    
// };
class Node {
  public:
  Node * links[26];
  int cntEndWith = 0;
  int cntPrefix = 0;

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL);
  }
  Node * get(char ch) {
    return links[ch - 'a'];
  }
  void put(char ch, Node * node) {
    links[ch - 'a'] = node;
  }
  void increaseEnd() {
    cntEndWith++;
  }
  void increasePrefix() {
    cntPrefix++;
  }
  void reduceEnd() {
    cntEndWith--;
  }
  void reducePrefix() {
    cntPrefix--;
  }
  int getEnd() {
    return cntEndWith;
  }
  int getPrefix() {
    return cntPrefix;
  }
};



class Trie{

    public:
    Node* root;
    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* tmp=root;
        for(char c : word){
            if(tmp->containsKey(c)==false){
                tmp->put(c,new Node());
            }
           
            tmp=tmp->get(c);
            tmp->increasePrefix();
           
        }
        tmp->increaseEnd();
        
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* tmp=root;
        for(char c : word){
            if(tmp->containsKey(c)==false) return 0;
            tmp=tmp->get(c);
        }
        return tmp->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* tmp=root;
        for(char c : word){
            if(tmp->containsKey(c)==NULL) return 0;
            tmp=tmp->get(c);
        }
        return tmp->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* tmp=root;
        for(char c : word){
            if(tmp->containsKey(c)==NULL) return;
            tmp=tmp->get(c);
            tmp->reducePrefix();
        }
        tmp->reduceEnd();
    }
};
