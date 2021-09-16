// computes number of prime less than or equal to n, using the Sieve of Eratosthenes
// ie n = 25, returns 9: 2, 3, 5, 7, 11, 13, 17, 19, 23

int primeSieves(int n){
  boolean[] isPrime = new boolean[n+1]; 
  for(int i = 2; i<=n; i++)
    isPrime[i] = true; 
  
  int res = n-1; 
  for(int factor = 2; factor * factor <= n; factor++){
    if(isPrime[factor]){
      for(int multiple = factor*factor; multiple <= n; multiple += factor){
        if(isPrime[multiple]){
          isPrime[multiple] = false;
          res--; 
        }
      }
    }
  }
  return res; 
}
