#include <bits/stdc++.h>
using namespace std;

// REQUIRES: 
// n connected nodes numbered 0 to n-1 
// edges[i] = {a,b}, represents an undirected connection between nodes a and b

// EFFECTS:
// returns critical edges of the graph 
// res[i] = {x,y}, where the edge connecting node x and y is critical

vector<vector<int>> criticalEdges(vector<vector<int>>& edges, int n){
  vector<vector<int>> g(n, vector<int>()); 
  for(auto& e : edges){
    g[e[0]].push_back(e[1]); 
    g[e[1]].push_back(e[0]); 
  }

  vector<int> rank(n), id(n, -1); 
  vector<vector<int>> res; 
  int time = 0; 
  
  dfs(0, -1, g, rank, id, res, time); 
  return res; 
}

void dfs(int cur, int parent, vector<vector<int>>& g, vector<int>& rank, vector<int>& id, vector<vector<int>>& res, int& time){
  rank[cur] = id[cur] = time++; 
  
  for(int& next : g[cur]){
    if(next == parent)
      continue; 
    else if(id[next] == -1){ // never visited
      dfs(next, cur, g, rank, id, res, time); 
      rank[cur] = min(rank[cur], rank[next]); 
      if(rank[next] > id[cur])
        res.push_back({cur, next}); 
    }
    else
      rank[cur] = min(rank[cur], id[next]); 
  }
}