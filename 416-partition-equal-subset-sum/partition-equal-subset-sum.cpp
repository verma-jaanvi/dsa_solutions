class Solution {
public:
    bool fn(int n, int k, vector<int> &nums,vector<vector<int>> &dp){
        if(k == 0)  return true;
        if(n == 0)  return k == nums[0];

        if(dp[n][k] != -1)  return dp[n][k];
        bool nt = fn(n-1, k, nums, dp);
        bool t = false;
        if(nums[n] <= k)    t = fn(n-1, k - nums[n], nums, dp);
        return dp[n][k] = t | nt;  
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums)   sum+= i;
        if(sum&1)   return false;
        vector<vector<int>> dp(nums.size(), vector<int>(sum/2 +1, -1));
        return fn(nums.size()-1, sum/2, nums, dp);
    }
};