# algo-templates
Templates for algorithms and data structures 

- **[KMP]** - Finds the index of the first occurrence of string needle in string haystack, or -1 if needle is not part of haystack. `O(m+n)` time.
- **[LIS]** - Finds the length of the longest strictly increasing subsequence in an array. `O(nlogn)` time.
- **[MST]** - Determines the min cost to connect all points in a edge-weighted undirected graph. 
  - **Kruskal's Algorithm** - Uses min heap to pick the smallest edge, and union-find to check if the edge is redudant. Connects these edges until all points are connected. 
  - **Prim's Algorithm** - Builds MST starting at some root. Pick the smallest edge from the MST to an unvisted node and connect edges until all points are connected.
- **[RangeQuery Mutable]** - Allows for range query for a mutable array. Supports update and query. 
  - **Fenwick Tree** - Data structure that can efficiently update elements and calculate prefix sums in a table of numbers. `O(logn)` update and query. 
  - **Segment Tree** - Tree data structure that can allow for range query/update in `O(logn)` time.   
- **[Shortest Path]**
  - **Bellman Ford** - Used to find shortest path from a single source to all other nodes even with negative weight edges. Can also detect a negative cycle (implies no shortest path). 
  - **Dijkstra** - Finds the shortest paths between nodes in a graph.
  - **Floyd-Warshall** - Finds the shortest paths between every pair of nodes in a graph. 
- **[Trie]** 
  - **Trie** - Data structure that stores prefixes of strings in a tree structure.
  - **Bitwise Trie** - Data structure that stores prefixes of integers in a tree structure. Can find max XOR of a number with the integers in the trie. 
- **[UnionFind]** - Data structure used to determine the connected components in a graph.
- **Binary Lifting** - Finds the lowest common ancestor of 2 nodes in `O(logn)` time.
- **GetPrimeFactors** - Finds the prime factorization of a number.
- **PrimeSieve** - Computes number of primes less than or equal to a number using the Sieve of Eratosthenes.
- **QuickSelect** - Returns the kth smallest number in an unsorted array in `O(n)` time on average.
- **Segment Tree** - Tree data structure that stores information about intervals. Allows for updating and querying intervals in `O(logn)` time.
- **Tarjan's** - Finds the critical edges of a graph (an edge that will disconnect parts of the graph when rememoved) in `O(|v| + |e|)` time.
- **Topological Sort** - Finds an linear ordering of a graph, such that for every edge u->v, u comes before v in the graph. 
- **gcd** - Finds the greatest common divisor of 2 numbers using Euclidean's algorithm.
- **pow** - Raises a number n to the kth power (using mods for larger numbers).

