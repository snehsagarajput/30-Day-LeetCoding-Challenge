/*


Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.

Example 1:
Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:
Input: [1,2,4,8]
Output: [1,2,4,8]


*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n=nums.size();
      sort(nums.begin(),nums.end()); 
    int dp[n];
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) 
    { 
        int mxm = 0; 
        for (int j = i + 1; j < n; j++) 
            if (nums[j] % nums[i] == 0) 
                mxm = max(mxm, dp[j]); 
  
        dp[i] = 1 + mxm; 
    }
    return *max_element(dp, dp + n);
    }
};
