class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n);
        vector<int> ans;
        // int prev = -1;
        for(int i = 0; i<n ; ++i){
            dp[i].push_back(nums[i]);
            for(int j = 0; j< i; ++j){
                if(nums[i] % nums[j] == 0 && dp[i].size() < dp[j].size() + 1){
                    dp[i] = dp[j];
                    dp[i].push_back(nums[i]);
                }
            }
        }

        for(auto it : dp){
            if(it.size() > ans.size()){
                ans = it;
            }
        }
        return ans;
    }
};