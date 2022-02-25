#include <bits/stdc++.h>
using namespace std;

// REQUIRES:
// cities are 0-indexed 
// start != end
// graph[i][j] = {neighboring city to i, cost from i to city}
// start = starting city 
// end = target city
// n = total number of cities


// EFFECTS:
// returns the minimum cost to reach end city from start city

int dkstra(vector<vector<pair<int, int>>> graph, int start, int end, int n){
  vector<bool> vis(n, false); 
  vector<int> best(n, INT32_MAX); 

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
  // into pq: {cost, city}, sorts by cost increasing
  pq.push({0, start});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop(); 
    int city = cur.second, cost = cur.first; 
    if(city == end)
        return cost; 
    if(vis[city])
      continue; 
    vis[city] = true; 

    for(auto& next : graph[city]){
      int nextCity = next.first, nextCost = cost + next.second; 
      if(vis[nextCity] || best[nextCity] <= nextCost)
        continue; 
    //   if(nextCity == end)
    //     return nextCost; 
      pq.push({nextCost, nextCity});
      best[nextCity] = nextCost;
    }
  }
  return -1; 
}