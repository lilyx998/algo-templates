List<Integer> getPrimeFactors(int n){
  List<Integer> res = new ArrayList<>(); 
  for(int factor = 2; factor * factor <= n; factor++){
    while(n % factor == 0){
      result.add(factor); 
      n /= factor; 
    }
  }
  if(n != 1)
    res.add(n); 
  return res;    
}