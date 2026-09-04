class Solution {
public:
    int fn(int idx, int buy, int transaction, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(transaction == 2 || idx == prices.size())    return 0;

        if(dp[idx][buy][transaction] != -1) return dp[idx][buy][transaction];

        if(buy) return dp[idx][buy][transaction] = max(prices[idx] + fn(idx+1, 0, transaction+1, prices, dp), fn(idx +1, 1, transaction, prices, dp));

        return dp[idx][buy][transaction] = max(fn(idx+1, 1, transaction, prices, dp) - prices[idx], fn(idx+1, 0, transaction, prices, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return fn(0, 0, 0, prices, dp);
    }
};