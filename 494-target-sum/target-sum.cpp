class Solution {
public:

    int fn(int i, vector<int> &nums, int tar, vector<vector<int>> &dp){
        if(i == 0){
            if(tar == 0 && nums[0] == 0) return 2;
            if(tar == 0 || nums[0] == tar)   return 1;
            return 0;
        }
        if(dp[i][tar] != -1)    return dp[i][tar];
        int nt = fn(i-1, nums, tar, dp);
        int t = 0;
        if(nums[i] <= tar)  t = fn(i-1, nums, tar - nums[i], dp);
        return dp[i][tar] = t + nt;
    }

    int findTargetSumWays(vector<int>& nums, int tar) {
        int sum = 0;
        for(int i : nums)   sum += i;
        if(sum < tar || (sum - tar) %2 != 0 )   return 0;
        vector<vector<int>> dp(nums.size(), vector<int>((sum - tar)/2 +1 , -1));
        return fn(nums.size()-1, nums, (sum-tar)/2, dp);
    }
};