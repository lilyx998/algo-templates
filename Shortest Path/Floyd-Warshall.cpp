#include <bits/stdc++.h>
using namespace std;

// REQUIRES 
// n nodes numbered 0 to n-1 
// edges[i] = {node1, node 2, weight}; may be directed or undirected edge
// no negative cycles in graph

// EFFECTS
// returns the shortest distance between any pair of nodes 
// dist[i][j] = the shortest distance between nodei and nodej

vector<vector<int>> shortestPathBetweenPairs(vector<vector<int>>& edges, int n){
  vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); 
  for(int i = 0; i<n; i++)
    dist[i][i] = 0; 

  for(auto& edge : edges){
    dist[edge[0]][edge[1]] = edge[2]; 
    // undirected: dist[edge[1]][edge[0]] = edge[2]; 
  }

  for(int j = 0; j<n; j++){
    for(int i = 0; i<n; i++){
      for(int k = 0; k<n; k++){
        if(dist[i][j] != INT_MAX && dist[j][k] != INT_MAX)
          dist[i][k] = min(dist[i][k], dist[i][j]+dist[j][k]);
      }
    }
  }
  return dist; 
}