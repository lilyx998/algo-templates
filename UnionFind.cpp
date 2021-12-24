#include <bits/stdc++.h>
using namespace std; 

class UnionFind{

private: 
  vector<int> parents;
  vector<int> rank; 
  vector<int> size; 
  int groups; 

public:
  UnionFind(int n) : parents(n), rank(n), size(n, 1){
    for(int i = 0; i<n; i++)
      parents[i] = i; 
    groups = n; 
  }

  int find(int i){
    if(parents[i] == i)
      return i; 
    return parents[i] = find(parents[i]); 
  }

  bool union_sets(int i, int j){
    i = find(i);
    j = find(j); 
    if(i == j)
      return false;
    
    groups--; 
    if(rank[i] == rank[j])
      rank[i]++;
    if(rank[i] > rank[j]){
      parents[j] = i;
      size[i] += size[j]; 
    }
    else{
      parents[i] = j; 
      size[j] += size[i]; 
    }
    return true; 
  }

  bool isConnected(int i, int j){
    return find(i) == find(j); 
  }

  int numGroups(){
    return groups; 
  }
};