class Solution {
public:
    int fn(int idx, int buy, int &fee, vector<int> &prices, vector<vector<int>> &dp){
        if(idx == prices.size())    return  0;

        if(dp[idx][buy] != -1)  return dp[idx][buy];
        if(buy) return dp[idx][buy] = max(prices[idx] - fee + fn(idx+1, 0, fee, prices, dp), fn(idx+1, 1, fee, prices, dp));

        return dp[idx][buy] = max(fn(idx+1, 1, fee, prices, dp) - prices[idx] , fn(idx+1, 0, fee, prices, dp)); 
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        // return fn(0, 0, fee, prices, dp);

        for(int idx = n-1; idx>=0; --idx){
            for(int buy = 0 ; buy<=1; buy++){
                if(buy)  dp[idx][buy] = max(prices[idx] - fee + dp[idx+1][0], dp[idx+1][1]);

                else dp[idx][buy] = max(dp[idx+1][1] - prices[idx] , dp[idx+1][0]); 
            }
        }
        return dp[0][0];

    }
};