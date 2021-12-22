#include <bits/stdc++.h>
using namespace std;

// REQUIRES:
// n nodes numbered 0 to n-1 
// edge[i] = {from, to}, where from and to are valid nodes

// EFFECTS:
// returns a possible total ordering of the graph
// if not possible total ordering (ie cycle), returns an empty vector

vector<int> topSort(vector<vector<int>>& edges, int n){
  vector<vector<int>> g(n, vector<int>()); 
  vector<int> indegree(n, 0); 
  for(auto& edge : edges){
    g[edge[0]].push_back(edge[1]); 
    indegree[edge[1]]++; 
  }

  queue<int> q; 
  for(int i = 0; i<n; i++)
    if(indegree[i] == 0)
      q.push(i); 

  vector<int> res; 
  while(!q.empty()){
    int cur = q.front(); 
    q.pop(); 
    res.push_back(cur); 
    for(int& next : g[cur]){
      indegree[next]--; 
      if(indegree[next] == 0)
        q.push(next); 
    }
  }

  return res.size() == n ? res : vector<int>(); 
}