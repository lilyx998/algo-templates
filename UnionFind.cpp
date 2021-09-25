public class UnionFind{
  int[] parents, rank, size; 
  int n, groups; 

  public UnionFind(int n){
    this.n = n; 
    parents = new int[n];
    rank = new int[n]; 
    for(int i = 0; i<n; i++)
      parents[i] = i; 
    size = new int[n]; 
    Arrays.fill(size, 1); 
    groups = n; 
  }

  int find(int i){
    if(parents[i] == i)
      return i; 
    return parents[i] = find(parents[i]); 
  }

  void union(int i, int j){
    i = find(i);
    j = find(j); 
    if(i == j)
      return;
    
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
  }

  boolean isConnected(int i, int j){
    return find(i) == find(j); 
  }
}
