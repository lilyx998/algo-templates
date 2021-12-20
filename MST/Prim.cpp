#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size(), root = 0; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    for(int j = 1; j<n; j++){
      int dist = abs(points[root][0] - points[j][0]) + abs(points[root][1] - points[j][1]); 
      pq.push({dist, j}); 
    }
    
    vector<bool> vis(n, false); 
    vis[root] = true; 
    int pointsConnected = 1, res = 0; 
    
    while(pointsConnected < n){
      auto edge = pq.top(); 
      pq.pop(); 
      int cost = edge.first, node = edge.second; 
      if(vis[node])
        continue; 
      vis[node] = true; 
      pointsConnected++; 
      res += cost; 
      
      for(int j = 0; j<n; j++){
        if(j == node)
          continue; 
        int dist = abs(points[node][0] - points[j][0]) + abs(points[node][1] - points[j][1]); 
        pq.push({dist, j}); 
      }
    }
    return res; 
  }
};