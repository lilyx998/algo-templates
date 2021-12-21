#include <bits/stdc++.h>
using namespace std; 

// REQUIRES:
// n nodes numbered from 0 to n-1
// edges[i] = [from, to, weight], weight is any int (+-)
// start is a valid node number

// EFFECTS: 
// returns the shortest distances from start node to all nodes 
// dist[i] = distance from start node to node i 
// if there is a negative cycle, no shortest distance exists, so returns an empty vector

vector<int> distanceFromStartToAllNodes(vector<vector<int>>& edges, int n, int start){
  vector<int> dist(n, INT_MAX); 

  dist[start] = 0; 
  for(int it = 1; it < n; it++){
    for(auto& edge : edges){
      int from = edge[0], to = edge[1], weight = edge[2]; 
      if(dist[from] != INT_MAX && dist[to] > dist[from]+weight)
        dist[to] = dist[from] + weight; 
    }
  }

  for(auto& edge : edges){
    int from = edge[0], to = edge[1], weight = edge[2]; 
    if(dist[from] != INT_MAX && dist[to] > dist[from]+weight)
      return vector<int>(); 
  }
  return dist; 
}