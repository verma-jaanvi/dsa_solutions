class Solution {
public:
    bool fn(int idx, vector<int>& stones, vector<vector<int>> &dp, int k) {
        if (idx == stones.size()-1) {
            return true;
        }
        if(dp[idx][k] != -1)    return dp[idx][k];
        // int st = idx == 0 ? idx + 1 : (idx == 1 ? idx : idx - 1);
        for (int i = idx+1; i < stones.size(); ++i) {

            int diff = abs(stones[i] - stones[idx]);
            if (diff >= k - 1 &&
                diff <= k + 1) {
                // k = k + diff;
                if(fn(i, stones, dp, diff)){
                    return dp[idx][k] = 1;
                }
            }else if(diff > k+1){
                break;
            }
        }

        return dp[idx][k] = 0;
    }

    bool canCross(vector<int>& stones) {
        // int k = 1;
        int n = stones.size();
        if(n > 1 && stones[1] != 1) return false;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fn(1, stones, dp, 1);

    }
};