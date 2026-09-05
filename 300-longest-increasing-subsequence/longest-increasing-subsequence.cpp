class Solution {
public:
    int fn(int idx, vector<int> &nums, int prev, vector<vector<int>> &dp){
        if(idx == nums.size())  return 0;

        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int nt = fn(idx+1, nums, prev, dp);
        int t = 0;
        if(prev == -1 || nums[idx] > nums[prev])   t = 1+fn(idx+1, nums, idx, dp);

        return dp[idx][prev+1] = max(nt, t);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return fn(0, nums, -1, dp);
    }
};