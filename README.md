# algo-templates
Templates for algorithms and data structures 

- Binary Lifting - Finds the lowest common ancestor of 2 nodes in O(logn) time 
- Dijkstra - Finds the shortest paths between nodes in a graph
- GetPrimeFactors - Finds the prime factorization of a number 
- PrimeSieve - Computes number of primes less than or equal to a number using the Sieve of Eratosthenes
- QuickSelect - Returns the kth smallest number in an unsorted array in O(n) time on average 
- UnionFind - Data structure used to determine the connected components in a graph
- gcd - Finds the greatest common divisor of 2 numbers using Euclidean's algorithm
- pow - Raises a number n to the kth power (using mods for larger numbers)
- MST - Determines the min cost to connect all points in a edge-weighted undirected graph. 
  - Kruskal's Algorithm - Uses min heap to pick the smallest edge, and union-find to check if the edge is redudant. Connects these edges until all points are connected. 
  - Prim's Algorithm - Builds MST starting at some root. Pick the smallest edge from the MST to an unvisted node and connect edges until all points are connected. 
