#include <bits/stdc++.h>
using namespace std;

class Trie {
  private: 
    bool isWord = false; 
    Trie* next[26] = {}; 

  public:
    Trie() {}

    void insert(string word) {
      Trie* node = this; 
      for(char& c : word){
        if(node->next[c-'a'] == nullptr)
          node->next[c-'a'] = new Trie(); 
        node = node->next[c-'a'];
      }
      node->isWord = true; 
    }

    bool search(string word) {
      Trie* node = this; 
      for(char& c : word){
        if(node->next[c-'a'] == nullptr)
          return false; 
        node = node->next[c-'a'];
      }
      return node->isWord; 
    }

    bool startsWith(string prefix) {
      Trie* node = this; 
      for(char& c : prefix){
        if(node->next[c-'a'] == nullptr)
          return false; 
        node = node->next[c-'a'];
      }
      return true; 
    }

    ~Trie(){
      Trie* node = this; 
      for(Trie* next : node->next)
        delete next; 
    }
};