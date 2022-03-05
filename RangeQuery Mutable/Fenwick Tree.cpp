#include <bits/stdc++.h>
using namespace std;

class BIT{
  int N; 
  vector<int> BITArray; 

  public: 
  BIT(vector<int> nums) : N(nums.size()+1), BITArray(N) {
    for(int i = 0; i<N-1; i++)
      update(i, nums[i]); 
  }

  void update(int idx, int delta){
    for(int i = idx + 1; i<N; i += (i&-i))
      BITArray[i] += delta; 
  }

  // returns sum of nums from [0, idx]
  int query(int idx){
    int res = 0; 
    for(int i = idx + 1; i>0; i -= (i&-i))
      res += BITArray[i]; 
    return res; 
  }
};