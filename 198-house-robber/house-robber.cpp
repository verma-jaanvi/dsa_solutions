class Solution {
public:
    void fn(vector<int> &nums, int i, vector<int> &dp, int n){
        if(i == n)    return;
        
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        fn(nums, i+1, dp, n);
        
    }

    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n== 1)   return nums[0];
        // if(n==2)    return nums[0]>nums[1] ? nums[0] : nums[1];

        vector<int> dp(n, -1);
        dp[0]= nums[0]; dp[1] = max(nums[0],nums[1]);
        fn(nums, 2, dp, n);
        int ans = 0;
        for(int i: dp)  ans = max(ans, i);
        return ans;
    }
};