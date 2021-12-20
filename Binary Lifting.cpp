#include <bits/stdc++.h>
using namespace std; 

class TreeAncestor {
  vector<vector<int>> p;
public:
  TreeAncestor(int n, vector<int>& parent) : p(17, vector<int>(n, -1)) {
    for(int node = 0; node<n; node++)
      p[0][node] = parent[node]; 
    
    for(int i = 1; i<=16; i++){
      for(int node = 0; node<n; node++){
        if(p[i-1][node] == -1)
          continue; 
        p[i][node] = p[i-1][p[i-1][node]];
      }
    }
  }

  int getKthAncestor(int node, int k) {
    for(int i = 16; i>=0; i--){
      if((k >> i) & 1){
        node = p[i][node]; 
        if(node == -1)
          return -1;
      }
    }
    return node; 
  }
};