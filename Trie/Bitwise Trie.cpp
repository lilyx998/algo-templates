#include <bits/stdc++.h>
using namespace std;

class BitTrie {
  private: 
    BitTrie* next[2] = {}; 

    int maxXor_impl(int n, int i){
      if(i == -1)
        return 0; 
      int bit = (n >> i) & 1;
      if(next[bit^1] != nullptr)
        return (1 << i) | next[bit^1]->maxXor_impl(n, i-1);
      return next[bit]->maxXor_impl(n, i-1); 
    }

  public:
    BitTrie() {}

    void insert(int n) {
      BitTrie* node = this; 
      for(int i = 31; i>=0; i--){
        int bit = (n >> i) & 1; 
        if(node->next[bit] == nullptr)
          node->next[bit] = new BitTrie(); 
        node = node->next[bit]; 
      }
    }

    bool search(int n) {
      BitTrie* node = this; 
      for(int i = 31; i>=0; i--){
        int bit = (n >> i) & 1; 
        if(next[bit] == nullptr)
          return false; 
        node = next[bit]; 
      }
      return true; 
    }

    // returns the maximum XOR of n and all the other numbers in this trie
    int maxXor(int n){
      return maxXor_impl(n, 31); 
    }

    ~BitTrie(){
      BitTrie* node = this; 
      for(BitTrie* next : node->next)
        delete next; 
    }
};  