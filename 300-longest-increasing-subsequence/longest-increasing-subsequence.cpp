class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for(int i = 0; i<n; ++i){
            int maxi = dp[i];
            for(int j = 0; j<i; ++j){
                if(nums[i] > nums[j])
                    maxi = max(maxi, dp[j]);
            }
            dp[i] = dp[i] + maxi;
            
        }
        int ans = 0;
        for(int i : dp) ans = max(ans, i);
        return ans - 1;
    }
};