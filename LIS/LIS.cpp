#include <bits/stdc++.h>
using namespace std;

// length of longest strictly increasing subsequence
int lengthOfLIS(const vector<int>& nums) {
    vector<int> dp; 
    for(int x : nums) {
        if(dp.empty() || dp[dp.size()-1] < x)
            dp.push_back(x); 
        else{
            auto it = lower_bound(dp.begin(), dp.end(), x);
            *it = x; 
        }
    }
    return dp.size();
}