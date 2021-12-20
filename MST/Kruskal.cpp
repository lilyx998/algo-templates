#include <bits/stdc++.h>
using namespace std;

class Solution {
  class UnionFind{
    vector<int> parent, rank; 
    public:
    UnionFind(int n){
      parent = vector<int>(n); 
      rank = vector<int>(n); 
      for(int i = 0; i<n; i++)
        parent[i] = i; 
    }

    int find(int i){
      if(parent[i] == i)
        return i; 
      return find(parent[i]); 
    }

    bool union_sets(int i, int j){
      i = find(i); 
      j = find(j); 
      if(i == j)
        return false; 
      if(rank[i] == rank[j])
        rank[i]++; 
      if(rank[i] > rank[j])
        parent[j] = i; 
      else
        parent[i] = j; 
      return true; 
    }
  };
  
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size(); 
    UnionFind uf(n); 
    
    vector<array<int, 3>> edges; 
    for(int i = 0; i<n; i++){
      for(int j = i+1; j<n; j++){
        int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]); 
        edges.push_back({dist, i , j});
      }
    }
    sort(edges.begin(), edges.end()); 
    
    int res = 0, nodesConnected = 1; 
    for(auto& edge : edges){
      if(uf.union_sets(edge[1], edge[2])){
        res += edge[0]; 
        nodesConnected++; 
        if(nodesConnected == n)
          break;
      }
    }
    return res; 
  }
};