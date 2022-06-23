
#include<bits/stdc++.h>

 
struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
};


class Trie {
  private: Node * root;
  public:
    Trie() {
      root = new Node();
    }
  
    void insert(int num) {
      Node * node = root;
      
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node -> containsKey(bit)) {
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }
  
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};



int maxXOR(vector < int > & arr1) {
  Trie trie;
    int n=arr1.size();
  for (int i = 0; i < n; i++) {
    trie.insert(arr1[i]);
  }
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, trie.findMax(arr1[i]));
  }
  return maxi;
}

int maximumXor(vector<int> A)
{
    // Write your code here.  
    return maxXOR(A);
    
}