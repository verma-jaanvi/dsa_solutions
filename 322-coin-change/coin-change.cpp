class Solution {
public:
    int fn(int idx, vector<int> &coins, int amt, vector<vector<int>> &dp){
        if(idx == 0){
            if(amt % coins[0] == 0) return amt/coins[0];
            return 1e9;
        }
        if(dp[idx][amt] != -1)  return dp[idx][amt];
        int nt = fn(idx-1, coins, amt, dp);
        int t = 1e9;
        if(coins[idx] <= amt)  t = 1+ fn(idx, coins, amt-coins[idx], dp);
        return dp[idx][amt] = min(nt, t);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() , vector<int>(amount+1, -1));
        int ans = fn(coins.size() - 1, coins, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};