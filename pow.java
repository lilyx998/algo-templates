private long pow(long n, int k){
  long res = 1; 
  while(k != 0){
    if(k % 2 == 1)
      res = (res*n) % MOD; 
    k >>> 1;
    n = (n*n) % MOD; 
  }
  return res; 
}