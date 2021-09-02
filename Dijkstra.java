/*
REQUIRES:
cities are 0-indexed 
start =/= end

graph[i] = neighboring cities to i and the cost to get from i to said city
start = starting city 
end = target city
n = total number of cities

returns the minimum cost to reach end city from start city
*/

int findMinCostToReachCity(List<int[]>[] graph, int start, int end, int n){
  boolean[] vis = new boolean[n]; 
  int[] best = new int[n]; 
  Arrays.fill(best, Integer.MAX_VALUE); 
  PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> (a[1] - b[1])); // sort by cost increasing
  pq.offer(new int[]{start, 0});

  while(!pq.isEmpty()){
    int[] cur = pq.poll(); 
    int city = cur[0], cost = cur[1]; 
    if(vis[city])
      continue; 
    vis[city] = true; 

    for(int[] next : graph[city]){
      int nextCity = next[0], nextCost = cost + next[1]; 
      if(vis[nextCity] || best[nextCity] <= nextCost)
        continue; 
      if(nextCity == end)
        return nextCost; 
      pq.offer(new int[]{nextCity, nextCost});
      best[nextCity] = nextCost;
    }
  }
  return -1; 
}